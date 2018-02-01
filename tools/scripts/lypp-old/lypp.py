#!/usr/bin/env python
#
# Copyright (c) 2017, Tom Rix
# All rights reserved.
#
# You may distribute under the terms of :
#
# the BSD 2-Clause license
#
# Any patches released for this software are to be released under these
# same license terms.
#
# BSD 2-Clause license:
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

import argparse
import os
import re
import tempfile
import sys

inc = list()
defs = list()
udefs = list()
verbose = False
ifdefs = list()
ifs = False

def handle_include(filename):
    global inc
    global defs
    global verbose
    global ifs 
    
    lineno = 0
    for line in open(filename,'r').readlines():
        lineno = lineno + 1

        m = re.search(r'^%endif.*', line)
        if m:
            if len(ifdefs):
                ifdefs.pop()
            else:
                print >> sys.stderr, 'Fatal Error : unmatched ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            continue
        
        m = re.search(r'^%ifdef .*', line)
        if m:
            d = line.lstrip('%ifdef')
            d = d.strip()
            ifs = True;
            if d not in defs:
                ifdefs.append(0)
            else:
                ifdefs.append(1)
            continue

        m = re.search(r'^%ifndef .*', line)
        if m:
            d = line.lstrip('%ifndef')
            d = d.strip()
            ifs = True;
            if d not in defs:
                ifdefs.append(1)
            else:
                ifdefs.append(0)
            continue

        m = re.search(r'^%else.*', line)
        if m:
            if not ifs :
                print >> sys.stderr, 'Fatal Error : else must procede an ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            if len(ifdefs):
                if ifdefs[-1] is 0:
                    ifdefs[-1] = 1
                else:
                    ifdefs[-1] = 0
                ifs = False
            else:
                print >> sys.stderr, 'Fatal Error : unmatched ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            continue

        m = re.search(r'^%elifdef .*', line)
        if m:
            d = line.lstrip('%elifdef')
            d = d.strip()
            if not ifs :
                print >> sys.stderr, 'Fatal Error : elifdef must procede an ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            if len(ifdefs):
                if ifdefs[-1] is 1:
                    ifdefs[-1] = -1
                elif ifdefs[-1] is not -1:
                    if d in defs:
                        ifdefs[-1] = 1
                    else:
                        ifdefs[-1] = 0
            else:
                print >> sys.stderr, 'Fatal Error : unmatched ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            continue

        m = re.search(r'^%elifndef .*', line)
        if m:
            d = line.lstrip('%elifndef')
            d = d.strip()
            if not ifs :
                print >> sys.stderr, 'Fatal Error : elifndef must procede an ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            if len(ifdefs):
                if ifdefs[-1] is 1:
                    ifdefs[-1] = -1
                elif ifdefs[-1] is not -1:
                    if d not in defs:
                        ifdefs[-1] = 1
                    else:
                        ifdefs[-1] = 0
            else:
                print >> sys.stderr, 'Fatal Error : unmatched ifdef at ' + filename + ':' + str(lineno)
                sys.exit(2)
            continue

        if len(ifdefs):
            if ifdefs[-1] is 0 or ifdefs[-1] is -1:
                continue
        
        m = re.search(r'^%def .*', line)
        if m:
            d = line.lstrip('%def')
            d = d.strip()
            if verbose:
                print >> sys.stderr, 'Define ' + d
            if d not in defs:
                defs.append(d)
            if d in udefs:
                udefs.remove(d)
            continue
        m = re.search(r'^%undef .*', line)
        if m:
            d = line.lstrip('%undef')
            d = d.strip()
            if verbose:
                print >> sys.stderr, 'Undefine ' + d
            if d in defs:
                defs.remove(d)
            if d not in udefs:
                udefs.append(d)
            continue
        m = re.search(r'^%include .*', line)
        if m:
            i = line.lstrip('%include')
            i = i.strip()
            if not os.path.exists(i):
                for p in inc:
                    ii = p + os.sep + i
                    if os.path.exists(ii):
                        i = ii
                        break
            if not os.path.exists(i):
                print >> sys.stderr, 'Fatal Error : the input file ' + i + ' does not exit'
                sys.exit(2)
            print '/* leaving ' + os.path.basename(filename) + ' at ' + str(lineno) + ' */'
            print '/* %include ' + os.path.basename(i) + ' */'
            handle_include(i)
            print ''
            print '/* returning to ' + os.path.basename(filename) + ' at ' + str(lineno) + ' */'
        else:
            print line,
    
def main():
    global inc
    cmdline = argparse.ArgumentParser(
        description = 'A lex/yacc preprocessor'
    )
    cmdline.add_argument('-v', '--verbose', help='verbose', action="store_true")
    cmdline.add_argument('-I', '--include', help='include path', action="append")
    cmdline.add_argument('-D', '--define', help='defines', action="append")
    cmdline.add_argument('-U', '--undefine', help='undefines', action="append")
    cmdline.add_argument('infile', help='input file', nargs='?')

    # Catch any unused args
    args, unknownargs = cmdline.parse_known_args()
    if unknownargs:
        a = ', '.join(unknownargs)
        print >> sys.stderr, sys.argv[0] + ': unknown option ' + a + '\n'
        cmdline.print_usage()
        sys.exit(2)

    # Past where not having file is ok
    if not args.infile:
        print >> sys.stderr, sys.argv[0] + ' must have an input file'
        cmdline.print_usage()
        sys.exit(2)

    if not os.path.exists(args.infile):
        print >> sys.stderr, 'Fatal Error : the input file ' + args.infile + ' does not exit'
        sys.exit(2)
    else :
        args.infile = os.path.abspath(args.infile)
    cwd = os.path.dirname(args.infile)

    if args.include:
        for i in args.include:
            if os.path.isabs(i):
                p = i
            else:
                p = os.path.abspath(cwd + os.sep + i)
            if os.path.isdir(p):
                inc.append(p)
            else:
                print >> sys.stderr, 'Warning : Include path ' + i + ' does not exist'

    if args.define:
        for i in args.define:
            if i not in defs:
                defs.append(i)

    if args.undefine:
        for i in args.undefine:
            if i in defs:
                defs.remove(i)

    if args.verbose:
        verbose = True
        for i in inc:
            print >> sys.stderr, 'Include path ' + i

    handle_include(args.infile)

    
if __name__ == "__main__":
    main()

#!/usr/bin/env python

import os
import platform
import pytest
import sys
import subprocess

script = '..' + os.sep + 'lypp.py'
input = 'input'
    
data_path = os.path.dirname(__file__)
if data_path:
    script = data_path + os.sep + '..' + os.sep + 'lypp.py'
    input = data_path + os.sep + 'input'

def test_ifn_1():
    global script
    f = input + os.sep + 'ifndef_1'
    t = subprocess.check_output([script, f]).strip()
    e = 'bar\nmar'
    assert(e == t)

def test_ifn_2():
    global script
    f = input + os.sep + 'ifndef_1'
    t = subprocess.check_output([script, '-D', 'foo', f]).strip()
    e = 'goo\nmar'
    assert(e == t)

def test_ifn_3():
    global script
    f = input + os.sep + 'ifndef_1'
    t = subprocess.check_output([script, '-D', 'foo', '-D', 'voo', f]).strip()
    e = 'mar'
    assert(e == t)


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

def test_def_1():
    global script
    f = input + os.sep + 'def_1'
    t = subprocess.check_output([script, f]).strip()
    e = 'goo\nmar\nloo'
    assert(e == t)

def test_def_2():
    global script
    f = input + os.sep + 'def_1'
    t = subprocess.check_output([script, '-U', 'foo', f]).strip()
    e = 'goo\nmar\nloo'
    assert(e == t)

def test_def_3():
    global script
    f = input + os.sep + 'def_1'
    t = subprocess.check_output([script, '-D', 'foo', f]).strip()
    e = 'bar\nmar\nloo'
    assert(e == t)



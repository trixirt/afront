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

def test_elif_1():
    global script
    f = input + os.sep + 'elif_1'
    t = subprocess.check_output([script, f]).strip()
    e = 'e'
    assert(e == t)

def test_elif_2():
    global script
    f = input + os.sep + 'elif_1'
    t = subprocess.check_output([script, '-D', 'foo', f]).strip()
    e = 'f'
    assert(e == t)

def test_elif_3():
    global script
    f = input + os.sep + 'elif_1'
    t = subprocess.check_output([script, '-D', 'voo', f]).strip()
    e = 'v'
    assert(e == t)

def test_elif_4():
    global script
    f = input + os.sep + 'elif_1'
    t = subprocess.check_output([script, '-D', 'loo', f]).strip()
    e = 'l'
    assert(e == t)





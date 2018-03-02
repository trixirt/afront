// Copyright (c) 2018 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK: Error: enum tag not unique to scope
void foo() {
    enum a { b } c;
    enum a { d } e;
}


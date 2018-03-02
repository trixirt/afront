// Copyright (c) 2018 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK: Error: struct tag not unique to scope
void foo() {
    enum a { b } c;
    struct a { int d; } e;
}


// Copyright (c) 2018 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK:
// enum type is unique to scope
enum a { d } e;
void foo() {
    enum a { b } c;
}


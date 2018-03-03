// Copyright (c) 2018 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK:
// incomplete/complete struct
struct a;
struct a { int a; };


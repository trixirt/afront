// Copyright (c) 2018 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK: Error: element redefined
struct a { int b; char a, b; };


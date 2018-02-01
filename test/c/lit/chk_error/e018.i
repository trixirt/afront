// Copyright (c) 2017 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK: Error: invalid int type
float int a;

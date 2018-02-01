// Copyright (c) 2017 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK: 
const volatile double a;
const const double b;
const volatile const double b;

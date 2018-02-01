// Copyright (c) 2017 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
// CHECK: Error: overspecified long type
signed long int long a;

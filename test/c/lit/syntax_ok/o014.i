// Copyright (c) 2018 Tom Rix,  All rights reserved.
// hexadecimal-floating-constants
// RUN: cc1 %s 2> %t.err

float d = 0x1p1;
float g = 0x1P1;
float j = 0x1p+1;
float m = 0x1P+1;
float q = 0x1p-1;
float t = 0x1P-1;

float d0 = 0x1p1f;
float g0 = 0x1P1f;
float not_gcc_builtin_j0 = 0x1p+1f;
float m0 = 0x1P+1f;
float q0 = 0x1p-1f;
float t0 = 0x1P-1f;

double d1 = 0x1p1F;
double g1 = 0x1P1F;
double not_gcc_builtin_j1 = 0x1p+1F;
double m1 = 0x1P+1F;
double q1 = 0x1p-1F;
double t1 = 0x1P-1F;

double d2 = 0x1p1l;
double g2 = 0x1P1l;
double j2 = 0x1p+1l;
double m2 = 0x1P+1l;
double q2 = 0x1p-1l;
double t2 = 0x1P-1l;

double d3 = 0x1p1L;
double g3 = 0x1P1L;
double j3 = 0x1p+1L;
double m3 = 0x1P+1L;
double q3 = 0x1p-1L;
double t3 = 0x1P-1L;

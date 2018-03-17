// Copyright (c) 2018 Tom Rix,  All rights reserved.
// decimal-floating-constants
// RUN: cc1 %s 2> %t.err

float d = 1e1;
float g = 1E1;
float j = 1e+1;
float m = 1E+1;
float q = 1e-1;
float t = 1E-1;

float d0 = 1e1f;
float g0 = 1E1f;
float not_gcc_builtin_j0 = 1e+1f;
float m0 = 1E+1f;
float q0 = 1e-1f;
float t0 = 1E-1f;

double d1 = 1e1F;
double g1 = 1E1F;
double not_gcc_builtin_j1 = 1e+1F;
double m1 = 1E+1F;
double q1 = 1e-1F;
double t1 = 1E-1F;

double d2 = 1e1l;
double g2 = 1E1l;
double j2 = 1e+1l;
double m2 = 1E+1l;
double q2 = 1e-1l;
double t2 = 1E-1l;

double d3 = 1e1L;
double g3 = 1E1L;
double j3 = 1e+1L;
double m3 = 1E+1L;
double q3 = 1e-1L;
double t3 = 1E-1L;

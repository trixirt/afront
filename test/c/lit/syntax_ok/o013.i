// Copyright (c) 2018 Tom Rix,  All rights reserved.
// hexadecimal-floating-constants
// RUN: cc1 %s 2> %t.err

float d = 0x1.p1;
float e = 0x1.1p1;
float f = 0x.1p1;
float g = 0x1.P1;
float h = 0x1.1P1;
float i = 0x.1P1;
float j = 0x1.p+1;
float k = 0x1.1p+1;
float l = 0x.1p+1;
float m = 0x1.P+1;
float n = 0x1.1P+1;
float o = 0x.1P+1;
float q = 0x1.p-1;
float r = 0x1.1p-1;
float s = 0x.1p-1;
float t = 0x1.P-1;
float u = 0x1.1P-1;
float v = 0x.1P-1;

float d0 = 0x1.p1f;
float e0 = 0x1.1p1f;
float f0 = 0x.1p1f;
float g0 = 0x1.P1f;
float h0 = 0x1.1P1f;
float i0 = 0x.1P1f;
float not_gcc_builtin_j0 = 0x1.p+1f;
float k0 = 0x1.1p+1f;
float l0 = 0x.1p+1f;
float m0 = 0x1.P+1f;
float n0 = 0x1.1P+1f;
float o0 = 0x.1P+1f;
float q0 = 0x1.p-1f;
float r0 = 0x1.1p-1f;
float s0 = 0x.1p-1f;
float t0 = 0x1.P-1f;
float u0 = 0x1.1P-1f;
float v0 = 0x.1P-1f;

double d1 = 0x1.p1F;
double e1 = 0x1.1p1F;
double f1 = 0x.1p1F;
double g1 = 0x1.P1F;
double h1 = 0x1.1P1F;
double i1 = 0x.1P1F;
double not_gcc_builtin_j1 = 0x1.p+1F;
double k1 = 0x1.1p+1F;
double l1 = 0x.1p+1F;
double m1 = 0x1.P+1F;
double n1 = 0x1.1P+1F;
double o1 = 0x.1P+1F;
double q1 = 0x1.p-1F;
double r1 = 0x1.1p-1F;
double s1 = 0x.1p-1F;
double t1 = 0x1.P-1F;
double u1 = 0x1.1P-1F;
double v1 = 0x.1P-1F;

double d2 = 0x1.p1l;
double e2 = 0x1.1p1l;
double f2 = 0x.1p1l;
double g2 = 0x1.P1l;
double h2 = 0x1.1P1l;
double i2 = 0x.1P1l;
double j2 = 0x1.p+1l;
double k2 = 0x1.1p+1l;
double l2 = 0x.1p+1l;
double m2 = 0x1.P+1l;
double n2 = 0x1.1P+1l;
double o2 = 0x.1P+1l;
double q2 = 0x1.p-1l;
double r2 = 0x1.1p-1l;
double s2 = 0x.1p-1l;
double t2 = 0x1.P-1l;
double u2 = 0x1.1P-1l;
double v2 = 0x.1P-1l;

double d3 = 0x1.p1L;
double e3 = 0x1.1p1L;
double f3 = 0x.1p1L;
double g3 = 0x1.P1L;
double h3 = 0x1.1P1L;
double i3 = 0x.1P1L;
double j3 = 0x1.p+1L;
double k3 = 0x1.1p+1L;
double l3 = 0x.1p+1L;
double m3 = 0x1.P+1L;
double n3 = 0x1.1P+1L;
double o3 = 0x.1P+1L;
double q3 = 0x1.p-1L;
double r3 = 0x1.1p-1L;
double s3 = 0x.1p-1L;
double t3 = 0x1.P-1L;
double u3 = 0x1.1P-1L;
double v3 = 0x.1P-1L;


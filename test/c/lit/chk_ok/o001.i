// Copyright (c) 2017 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
// RUN: FileCheck < %t.err %s
void a;
char b;
signed char c;
unsigned char d;
short e;
signed short f;
short int g;
signed short int h;
unsigned short i;
unsigned short int j;
int k;
signed l;
signed int m;
unsigned n;
unsigned int o;
long p;
signed long q;
long int r;
signed long int s;
unsigned long t;
unsigned long int u;
long long v;
signed long long w;
long long int x;
signed long long int y;
unsigned long long z;
unsigned long long int aa;
float ab;
double ac;
long double ad;

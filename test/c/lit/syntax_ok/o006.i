// Copyright (c) 2018 Tom Rix,  All rights reserved.
// c99 char constant
// RUN: cc1 %s 2> %t.err
int a = 'a';
int b = '\'';
int c = '\"';
int d = '\?';
int e = '\a';
int f = '\b';
int g = '\f';
int h = '\n';
int i = '\r';
int j = '\t';
int k = '\v';
int l = '\0';
int m = '\07';
int n = '\x0';
int o = '\xa';
int A = L'a';
int B = L'\'';
int C = L'\"';
int D = L'\?';
int E = L'\a';
int F = L'\b';
int G = L'\f';
int H = L'\n';
int I = L'\r';
int J = L'\t';
int K = L'\v';
int L = L'\0';
int M = L'\07';
int N = L'\x0';
int O = L'\xa';


// Copyright (c) 2018 Tom Rix,  All rights reserved.
// c11 char constant
// RUN: cc1 %s 2> %t.err
int a = u'a';
int b = u'\'';
int c = u'\"';
int d = u'\?';
int e = u'\a';
int f = u'\b';
int g = u'\f';
int h = u'\n';
int i = u'\r';
int j = u'\t';
int k = u'\v';
int l = u'\0';
int m = u'\07';
int n = u'\x0';
int o = u'\xa';
int A = U'a';
int B = U'\'';
int C = U'\"';
int D = U'\?';
int E = U'\a';
int F = U'\b';
int G = U'\f';
int H = U'\n';
int I = U'\r';
int J = U'\t';
int K = U'\v';
int L = U'\0';
int M = U'\07';
int N = U'\x0';
int O = U'\xa';

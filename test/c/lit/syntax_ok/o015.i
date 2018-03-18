// Copyright (c) 2018 Tom Rix,  All rights reserved.
// string-literal
// RUN: cc1 %s 2> %t.err
const char *a = "a";
const char *b = "\"";
const char *c = "\"";
const char *d = "\?";
const char *e = "\a";
const char *f = "\b";
const char *g = "\f";
const char *h = "\n";
const char *i = "\r";
const char *j = "\t";
const char *k = "\v";
const char *l = "\0";
const char *m = "\07";
const char *n = "\x0";
const char *o = "\xa";
const int *A = L"a";
const int *B = L"\"";
const int *C = L"\"";
const int *D = L"\?";
const int *E = L"\a";
const int *F = L"\b";
const int *G = L"\f";
const int *H = L"\n";
const int *I = L"\r";
const int *J = L"\t";
const int *K = L"\v";
const int *L = L"\0";
const int *M = L"\07";
const int *N = L"\x0";
const int *O = L"\xa";


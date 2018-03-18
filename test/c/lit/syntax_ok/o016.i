// Copyright (c) 2018 Tom Rix,  All rights reserved.
// string-literal
// RUN: cc1 %s 2> %t.err
unsigned short *a = u"a";
unsigned short *b = u"\"";
unsigned short *c = u"\"";
unsigned short *d = u"\?";
unsigned short *e = u"\a";
unsigned short *f = u"\b";
unsigned short *g = u"\f";
unsigned short *h = u"\n";
unsigned short *i = u"\r";
unsigned short *j = u"\t";
unsigned short *k = u"\v";
unsigned short *l = u"\0";
unsigned short *m = u"\07";
unsigned short *n = u"\x0";
unsigned short *o = u"\xa";
const unsigned int *A = U"a";
const unsigned int *B = U"\"";
const unsigned int *C = U"\"";
const unsigned int *D = U"\?";
const unsigned int *E = U"\a";
const unsigned int *F = U"\b";
const unsigned int *G = U"\f";
const unsigned int *H = U"\n";
const unsigned int *I = U"\r";
const unsigned int *J = U"\t";
const unsigned int *K = U"\v";
const unsigned int *L = U"\0";
const unsigned int *M = U"\07";
const unsigned int *N = U"\x0";
const unsigned int *O = U"\xa";


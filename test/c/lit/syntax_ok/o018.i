// Copyright (c) 2018 Tom Rix,  All rights reserved.
// string-literal universal char
// RUN: cc1 %s 2> %t.err
unsigned short *a = u"\u1122";
unsigned short *b = u"\U00001122";
unsigned int *c = U"\u1122";
unsigned int *d = U"\U00001122";
int *e = L"\u1122";
int *f = L"\U00001122";
char *g = u8"\u1122";
char *h = u8"\U00001122";


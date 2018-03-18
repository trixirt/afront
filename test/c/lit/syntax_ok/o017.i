// Copyright (c) 2018 Tom Rix,  All rights reserved.
// string-literal
// RUN: cc1 %s 2> %t.err
char *a = u8"a";
char *b = u8"\"";
char *c = u8"\"";
char *d = u8"\?";
char *e = u8"\a";
char *f = u8"\b";
char *g = u8"\f";
char *h = u8"\n";
char *i = u8"\r";
char *j = u8"\t";
char *k = u8"\v";
char *l = u8"\0";
char *m = u8"\07";
char *n = u8"\x0";
char *o = u8"\xa";

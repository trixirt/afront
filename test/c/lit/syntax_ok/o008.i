// Copyright (c) 2018 Tom Rix,  All rights reserved.
// universal char
// RUN: cc1 %s 2> %t.err
int a = u'\u1122';
int b = u'\U00001122';
int c = U'\u1122';
int d = U'\U00001122';
int e = L'\u1122';
int f = L'\U00001122';


// Copyright (c) 2018 Tom Rix,  All rights reserved.
// RUN: cc1 %s 2> %t.err
typedef struct
{
    int a;
} t2;
typedef struct
{
    t2 b;
} t3;
typedef struct
{
    t2 b;
} t4;


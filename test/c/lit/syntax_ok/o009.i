// Copyright (c) 2018 Tom Rix,  All rights reserved.
// digraph
// RUN: cc1 %s 2> %t.err
void foo() <%
    int a<: 1 :> = { 5 };
%>

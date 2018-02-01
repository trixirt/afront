// Copyright (c) 2018 Tom Rix,  All rights reserved.
int main() {
    unsigned short a = 0xaa55;
    unsigned short c, d;
    c = ~a;
    d = ??- a;
    if (c == d)
	return 0;
    else
	return 1;
}

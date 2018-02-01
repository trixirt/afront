// Copyright (c) 2018 Tom Rix,  All rights reserved.
int main() {
    unsigned short a = 0xaa55;
    unsigned short b = 0x7711;
    unsigned short c, d;
    c = a ^ b;
    d = a ??' b;
    if (c == d)
	return 0;
    else
	return 1;
}

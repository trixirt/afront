// Copyright (c) 2018 Tom Rix,  All rights reserved.
int main() {
    unsigned short a = 0;
    unsigned short b = 0xaa55;
    unsigned short c, d;
    if (a ??!??! b)
	return 0;
    else
	return 1;
}

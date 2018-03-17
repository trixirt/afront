/*
 * Copyright (c) 2017-2018 Tom Rix
 * All rights reserved.
 *
 * You may distribute under the terms of :
 *
 * the BSD 2-Clause license
 *
 * Any patches released for this software are to be released under these
 * same license terms.
 *
 * BSD 2-Clause license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

hexadecimal_prefix   (0x|0X)

unsigned_suffix (u|U)
long_suffix (l|L)
long_long_suffix (ll|LL)
integer_suffix  (({unsigned_suffix}{long_suffix}?)|({unsigned_suffix}{long_long_suffix})|({long_suffix}{unsigned_suffix}?)|({long_long_suffix}{unsigned_suffix}?))

decimal_constant     {nonzero_digit}{digit}*{integer_suffix}?
octal_constant       0{octal_digit}*{integer_suffix}?
hexadecimal_constant {hexadecimal_prefix}{hexadecimal_digit}+{integer_suffix}?
integer_constant ({decimal_constant}|{octal_constant}|{hexadecimal_constant})

floating_suffix	(f|F|l|L)
sign [-+]
exponent [eE]
digit_sequence {digit}+
exponent_part {exponent}{sign}?{digit_sequence}
fractional_constant (({digit_sequence}?"."{digit_sequence})|({digit_sequence}"."))
decimal_floating_constant (({fractional_constant}{exponent_part}?{floating_suffix}?)|({digit_sequence}{exponent_part}{floating_suffix}?))

floating_constant    {decimal_floating_constant}

constant_char_prefix  (u|U|L)?
c_char_graphic_char       ("!"|";"|"\""|"<"|"#"|"="|"%"|">"|"&"|"?"|"["|"("|"/"|"~"|":"|" "|"\t"|"\v"|"\r")
simple_escape_sequence ("\\'"|"\\\""|"\\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v")
octal_escape_sequence "\\"{octal_digit}+
hexadecimal_escape_sequence "\\x"{hexadecimal_digit}+
hex_quad {hexadecimal_digit}{4}
universal_character_name ("\\u"{hex_quad}|"\\U"{hex_quad}{hex_quad})
escape_sequence ({simple_escape_sequence}|{octal_escape_sequence}|{hexadecimal_escape_sequence}|{universal_character_name})
c_char  [a-zA-Z0-9]|{c_char_graphic_char}|{escape_sequence}
c_char_sequence  {c_char}
character_constant {constant_char_prefix}"'"{c_char_sequence}"'"
		       

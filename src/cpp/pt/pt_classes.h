/*
 * Copyright (c) 2019 Tom Rix
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

/* multiple includes is ok */

// Define PT_CLASS(classname) to do something
#ifndef PT_CLASS
// If you did not, then it is foreward decl of the class
#define PT_CLASS(C) class C;
#endif

PT_CLASS(control_line)
PT_CLASS(cpp_conditional_expr)
PT_CLASS(defined)
PT_CLASS(elif_groups)
PT_CLASS(elif_group)
PT_CLASS(else_group)
PT_CLASS(endif_line)
PT_CLASS(group_part)
PT_CLASS(group)
PT_CLASS(if_group)
PT_CLASS(if_section)
PT_CLASS(new_line)
PT_CLASS(non_directive)
PT_CLASS(pp_tokens)
PT_CLASS(preprocessing_file)
PT_CLASS(preprocessing_token)
PT_CLASS(replacement_list)
PT_CLASS(text_line)
PT_CLASS(white_space)

#undef PT_CLASS

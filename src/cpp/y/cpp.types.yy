/* Copyright (c) 2019 Tom Rix
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

%type <std::shared_ptr<control_line>> control_line;
%type <std::shared_ptr<elif_groups>> elif_groups;
%type <std::shared_ptr<elif_group>> elif_group;
%type <std::shared_ptr<else_group>> else_group;
%type <std::shared_ptr<endif_line>> endif_line;
%type <std::shared_ptr<group_part>> group_part;
%type <std::shared_ptr<group>> group;
%type <std::shared_ptr<if_group>> if_group;
%type <std::shared_ptr<if_section>> if_section;
%type <std::shared_ptr<new_line>> new_line;
%type <std::shared_ptr<non_directive>> non_directive;
%type <std::shared_ptr<pp_tokens>> pp_tokens;
%type <std::shared_ptr<preprocessing_file>> preprocessing_file;
%type <std::shared_ptr<preprocessing_token>> preprocessing_token;
%type <std::shared_ptr<replacement_list>> replacement_list;
%type <std::shared_ptr<text_line>> text_line;
%type <std::shared_ptr<white_space>> white_space;
%type <std::shared_ptr<white_space>> white_space_or_nospace;
%type <std::shared_ptr<white_space>> nospace;



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
#ifndef AFRONT_C_PT_DEFINES_H
#define AFRONT_C_PT_DEFINES_H

// 6.7.1 storage-class-specifier
#define STORAGE_CLASS_SPECIFIER_TYPEDEF       (1 << 0)
#define STORAGE_CLASS_SPECIFIER_EXTERN        (1 << 1)
#define STORAGE_CLASS_SPECIFIER_STATIC        (1 << 2)
#define STORAGE_CLASS_SPECIFIER_THREAD_LOCAL  (1 << 3)
#define STORAGE_CLASS_SPECIFIER_AUTO          (1 << 4)
#define STORAGE_CLASS_SPECIFIER_REGISTER      (1 << 5)

// 6.7.2 type-specifier
#define TYPE_SPECIFIER_VOID                   (1 << 0)
#define TYPE_SPECIFIER_CHAR                   (1 << 1)
#define TYPE_SPECIFIER_SHORT                  (1 << 2)
#define TYPE_SPECIFIER_INT                    (1 << 3)
#define TYPE_SPECIFIER_LONG                   (1 << 4)
#define TYPE_SPECIFIER_LONG_LONG              (1 << 5)
#define TYPE_SPECIFIER_FLOAT                  (1 << 6)
#define TYPE_SPECIFIER_DOUBLE                 (1 << 7)
#define TYPE_SPECIFIER_SIGNED                 (1 << 8)
#define TYPE_SPECIFIER_UNSIGNED               (1 << 9)
#define TYPE_SPECIFIER_BOOL                   (1 << 10)
#define TYPE_SPECIFIER_COMPLEX                (1 << 11)
#define TYPE_SPECIFIER_ATOMIC_TYPE            (1 << 12)
#define TYPE_SPECIFIER_STRUCT_OR_UNION        (1 << 13)
#define TYPE_SPECIFIER_ENUM                   (1 << 14)
#define TYPE_SPECIFIER_TYPEDEF                (1 << 15)

// 6.7.3 type-qualifer
#define TYPE_QUALIFIER_CONST                  (1 << 0)
#define TYPE_QUALIFIER_RESTRICT               (1 << 1)
#define TYPE_QUALIFIER_VOLATILE               (1 << 2)
#define TYPE_QUALIFIER_ATOMIC                 (1 << 3)

// 6.7.4 function-specifier
#define FUNCTION_SPECIFIER_INLINE             (1 << 0)
#define FUNCTION_SPECIFIER_NORETURN           (1 << 1)

// 6.7.5 alignment-specifer 
#define ALIGNMENT_SPECIFIER_ALIGNAS_TYPE      (1 << 0)
#define ALIGNMENT_SPECIFIER_ALIGNAS_CONSTANT  (1 << 1)

#endif

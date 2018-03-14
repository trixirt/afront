%token END 0
%token <class lex_token> LT
%token <class lex_token> PTR
%token <class lex_token> GT
%token <class lex_token> EQ
%token <class lex_token> COM
%token <class lex_token> ADD
%token <class lex_token> SUB
%token <class lex_token> DOT
%token <class lex_token> MUL
%token <class lex_token> DIV
%token <class lex_token> TIL
%token <class lex_token> EXL
%token <class lex_token> QUE
%token <class lex_token> OPA CPA
%token <class lex_token> OBK CBK
%token <class lex_token> OBR CBR
%token <class lex_token> COL
%token <class lex_token> MOD
%token <class lex_token> XOR
%token <class lex_token> SCO
%token <class lex_token> SQU
%token <class lex_token> AMP
%token <class lex_token> AMPAMP
%token <class lex_token> OR
%token <class lex_token> OROR
%token <class lex_token> LTLT
%token <class lex_token> GTGT
%token <class lex_token> LTE
%token <class lex_token> GTE
%token <class lex_token> ADD_ASSIGN
%token <class lex_token> AND_ASSIGN
%token <class lex_token> AUTO
%token <class lex_token> CHAR
%token <class lex_token> CONST
%token <class lex_token> CONSTANT
%token <class lex_token> DEC
%token <class lex_token> DIV_ASSIGN
%token <class lex_token> DOUBLE
%token <class lex_token> ELIPSIS
%token <class lex_token> EQEQ
%token <class lex_token> ENUM
%token <class lex_token> EXTERN
%token <class lex_token> FLOAT
%token <class lex_token> IDENTIFIER
%token <class lex_token> TYPENAME_IDENTIFIER
%token <class lex_token> INC
%token <class lex_token> INT
%token <class lex_token> LEFT_ASSIGN
%token <class lex_token> LONG
%token <class lex_token> MOD_ASSIGN
%token <class lex_token> MUL_ASSIGN
%token <class lex_token> NE
%token <class lex_token> OR_ASSIGN
%token <class lex_token> RIGHT_ASSIGN
%token <class lex_token> REGISTER
%token <class lex_token> SHORT
%token <class lex_token> SIZEOF
%token <class lex_token> SIGNED
%token <class lex_token> STATIC
%token <class lex_token> STRING_LITERAL
%token <class lex_token> STRUCT
%token <class lex_token> SUB_ASSIGN
%token <class lex_token> TYPEDEF
%token <class lex_token> UNION
%token <class lex_token> UNSIGNED
%token <class lex_token> VOID
%token <class lex_token> VOLATILE
%token <class lex_token> XOR_ASSIGN
%token <class lex_token> BREAK
%token <class lex_token> CASE
%token <class lex_token> CONTINUE
%token <class lex_token> DEFAULT
%token <class lex_token> DO
%token <class lex_token> ELSE
%token <class lex_token> FOR
%token <class lex_token> GOTO
%token <class lex_token> IF
%token <class lex_token> RETURN
%token <class lex_token> SWITCH
%token <class lex_token> WHILE

%ifdef c99

%token <class lex_token> INLINE
%token <class lex_token> RESTRICT
%token <class lex_token> _BOOL
%token <class lex_token> _COMPLEX
%token <class lex_token> _IMAGINARY

%endif

%ifdef c11

%token <class lex_token> _ALIGNAS
%token <class lex_token> _ALIGNOF
%token <class lex_token> _ATOMIC
%token <class lex_token> _GENERIC
%token <class lex_token> _NORETURN
%token <class lex_token> _STATIC_ASSERT
%token <class lex_token> _THREAD_LOCAL

%endif

%token <class lex_token> UNSUPPORTED_INPUT_CHAR

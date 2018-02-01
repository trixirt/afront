%token END 0
%token <class lex::token> LT
%token <class lex::token> PTR
%token <class lex::token> GT
%token <class lex::token> EQ
%token <class lex::token> COM
%token <class lex::token> ADD
%token <class lex::token> SUB
%token <class lex::token> DOT
%token <class lex::token> MUL
%token <class lex::token> DIV
%token <class lex::token> TIL
%token <class lex::token> EXL
%token <class lex::token> QUE
%token <class lex::token> OPA CPA
%token <class lex::token> OBK CBK
%token <class lex::token> OBR CBR
%token <class lex::token> COL
%token <class lex::token> MOD
%token <class lex::token> XOR
%token <class lex::token> SCO
%token <class lex::token> SQU
%token <class lex::token> AMP
%token <class lex::token> AMPAMP
%token <class lex::token> OR
%token <class lex::token> OROR
%token <class lex::token> LTLT
%token <class lex::token> GTGT
%token <class lex::token> LTE
%token <class lex::token> GTE
%token <class lex::token> ADD_ASSIGN
%token <class lex::token> AND_ASSIGN
%token <class lex::token> AUTO
%token <class lex::token> CHAR
%token <class lex::token> CONST
%token <class lex::token> CONSTANT
%token <class lex::token> DEC
%token <class lex::token> DIV_ASSIGN
%token <class lex::token> DOUBLE
%token <class lex::token> ELIPSIS
%token <class lex::token> EQEQ
%token <class lex::token> ENUM
%token <class lex::token> EXTERN
%token <class lex::token> FLOAT
%token <class lex::token> IDENTIFIER
%token <class lex::token> TYPENAME_IDENTIFIER
%token <class lex::token> INC
%token <class lex::token> INT
%token <class lex::token> LEFT_ASSIGN
%token <class lex::token> LONG
%token <class lex::token> MOD_ASSIGN
%token <class lex::token> MUL_ASSIGN
%token <class lex::token> NE
%token <class lex::token> OR_ASSIGN
%token <class lex::token> RIGHT_ASSIGN
%token <class lex::token> REGISTER
%token <class lex::token> SHORT
%token <class lex::token> SIZEOF
%token <class lex::token> SIGNED
%token <class lex::token> STATIC
%token <class lex::token> STRING_LITERAL
%token <class lex::token> STRUCT
%token <class lex::token> SUB_ASSIGN
%token <class lex::token> TYPEDEF
%token <class lex::token> UNION
%token <class lex::token> UNSIGNED
%token <class lex::token> VOID
%token <class lex::token> VOLATILE
%token <class lex::token> XOR_ASSIGN
%token <class lex::token> BREAK
%token <class lex::token> CASE
%token <class lex::token> CONTINUE
%token <class lex::token> DEFAULT
%token <class lex::token> DO
%token <class lex::token> ELSE
%token <class lex::token> FOR
%token <class lex::token> GOTO
%token <class lex::token> IF
%token <class lex::token> RETURN
%token <class lex::token> SWITCH
%token <class lex::token> WHILE

%ifdef c99

%token <class lex::token> INLINE
%token <class lex::token> RESTRICT
%token <class lex::token> _BOOL
%token <class lex::token> _COMPLEX
%token <class lex::token> _IMAGINARY

%endif

%ifdef c11

%token <class lex::token> _ALIGNAS
%token <class lex::token> _ALIGNOF
%token <class lex::token> _ATOMIC
%token <class lex::token> _GENERIC
%token <class lex::token> _NORETURN
%token <class lex::token> _STATIC_ASSERT
%token <class lex::token> _THREAD_LOCAL

%endif


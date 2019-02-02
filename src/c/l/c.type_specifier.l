"void"                      { LEXTOK(VOID);       }
"char"                      { LEXTOK(CHAR); }
"short"                     { LEXTOK(SHORT);      }
"int"                       { LEXTOK(INT); }
"long"                      { LEXTOK(LONG); }
"float"                     { LEXTOK(FLOAT); }
"double"                    { LEXTOK(DOUBLE); }
"signed"                    { LEXTOK(SIGNED);     }
"unsigned"                  { LEXTOK(UNSIGNED);   }
%ifdef c99
"_Bool"                     { LEXTOK(_BOOL); }
"_Complex"                  { LEXTOK(_COMPLEX); }
%endif

<*>"void"        { LEXTOK(VOID);       }
<*>"char"        { LEXTOK(CHAR);       }
<*>"short"       { LEXTOK(SHORT);      }
<*>"int"         { LEXTOK(INT);        }
<*>"long"        { LEXTOK(LONG);       }
<*>"float"       { LEXTOK(FLOAT);      }
<*>"double"      { LEXTOK(DOUBLE);     }
<*>"signed"      { LEXTOK(SIGNED);     }
<*>"unsigned"    { LEXTOK(UNSIGNED);   }
<*>"union"       { LEXTOK(UNION);      }
<*>"struct"      { LEXTOK(STRUCT);     }
<*>"enum"        { LEXTOK(ENUM);       }
%ifdef c99
<*>"_Bool"       { LEXTOK(_BOOL);      }
<*>"_Complex"    { LEXTOK(_COMPLEX);   }
<*>""_Imaginary" { LEXTOK(_IMAGINARY); }
%endif

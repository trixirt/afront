%ifndef c_start
%def c_start *
%endif

<c_start>"void"        { LEXTOK(VOID);       }
<c_start>"char"        { LEXTOK(CHAR);       }
<c_start>"short"       { LEXTOK(SHORT);      }
<c_start>"int"         { LEXTOK(INT);        }
<c_start>"long"        { LEXTOK(LONG);       }
<c_start>"float"       { LEXTOK(FLOAT);      }
<c_start>"double"      { LEXTOK(DOUBLE);     }
<c_start>"signed"      { LEXTOK(SIGNED);     }
<c_start>"unsigned"    { LEXTOK(UNSIGNED);   }
<c_start>"union"       { LEXTOK(UNION);      }
<c_start>"struct"      { LEXTOK(STRUCT);     }
<c_start>"enum"        { LEXTOK(ENUM);       }
%ifdef c99
<c_start>"_Bool"       { LEXTOK(_BOOL);      }
<c_start>"_Complex"    { LEXTOK(_COMPLEX);   }
<c_start>"_Imaginary"  { LEXTOK(_IMAGINARY); }
%endif

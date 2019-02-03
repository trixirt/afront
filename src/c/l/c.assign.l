%ifndef c_start
%def c_start *
%endif

<c_start>"&="       { LEXTOK(AND_ASSIGN); }
<c_start>"+="       { LEXTOK(ADD_ASSIGN); }
<c_start>"-="       { LEXTOK(SUB_ASSIGN); }
<c_start>"*="       { LEXTOK(MUL_ASSIGN); }
<c_start>"%="       { LEXTOK(MOD_ASSIGN); }
<c_start>"|="       { LEXTOK(OR_ASSIGN); }
<c_start>"^="       { LEXTOK(XOR_ASSIGN); }
<c_start>"/="       { LEXTOK(DIV_ASSIGN); }
<c_start>"<<="      { LEXTOK(LEFT_ASSIGN); }
<c_start>">>="      { LEXTOK(RIGHT_ASSIGN); }


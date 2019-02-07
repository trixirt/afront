%ifndef common_start
%def common_start *
%endif

<common_start>"<"        { LEXTOK(LT); }
<common_start>">"        { LEXTOK(GT); }
<common_start>"="        { LEXTOK(EQ); }
<common_start>"+"        { LEXTOK(PLU); }
<common_start>"-"        { LEXTOK(MIN); }
<common_start>","        { LEXTOK(COM); }
<common_start>"&"        { LEXTOK(AMP); }
<common_start>"."        { LEXTOK(DOT); }
<common_start>"*"        { LEXTOK(MUL); }
<common_start>"["        { LEXTOK(OBK); }
<common_start>"]"        { LEXTOK(CBK); }
<common_start>"("        { LEXTOK(OPA); }
<common_start>")"        { LEXTOK(CPA); }
<common_start>":"        { LEXTOK(COL); }
<common_start>";"        { LEXTOK(SCO); }
<common_start>"{"        { LEXTOK(OBR); }
<common_start>"}"        { LEXTOK(CBR); }
<common_start>"'"        { LEXTOK(SQU); }
<common_start>"|"        { LEXTOK(VER); }
<common_start>"/"        { LEXTOK(SL); }
<common_start>"?"        { LEXTOK(QUE); }
<common_start>"!"        { LEXTOK(EXL); }
<common_start>"%"        { LEXTOK(PCT); }
<common_start>"~"        { LEXTOK(TIL); }
<common_start>"^"        { LEXTOK(CIR); }
<common_start>"=="       { LEXTOK(EQEQ); }
<common_start>"<<"       { LEXTOK(LTLT); }
<common_start>">>"       { LEXTOK(GTGT); }
<common_start>"<="       { LEXTOK(LTEQ); }
<common_start>">="       { LEXTOK(GTEQ); }
<common_start>"&&"       { LEXTOK(AMPAMP); }
<common_start>"::"       { LEXTOK(COLCOL); }

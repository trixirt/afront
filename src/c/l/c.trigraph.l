%ifndef c_start
%def c_start *
%endif

<c_start>"??-"     { LEXTOK(TIL); }
<c_start>"??("     { LEXTOK(OBK); }
<c_start>"??)"     { LEXTOK(CBK); }
<c_start>"??<"     { LEXTOK(OBR); }
<c_start>"??>"     { LEXTOK(CBR); }
<c_start>"??!"     { LEXTOK(VER); }
<c_start>"??!|"    { LEXTOK(OROR); }
<c_start>"|??!"    { LEXTOK(OROR); }
<c_start>"??!??!"  { LEXTOK(OROR); }
<c_start>"??'"     { LEXTOK(CIR); }
<c_start>"??!="    { LEXTOK(OR_ASSIGN); }
<c_start>"??'="    { LEXTOK(XOR_ASSIGN); }
<c_start>"??/\n"   { this->line(); LEXTOK(NL); }

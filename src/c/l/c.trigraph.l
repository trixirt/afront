<*>"??-"     { LEXTOK(TIL); }
<*>"??("     { LEXTOK(OBK); }
<*>"??)"     { LEXTOK(CBK); }
<*>"??<"     { LEXTOK(OBR); }
<*>"??>"     { LEXTOK(CBR); }
<*>"??!"     { LEXTOK(VER); }
<*>"??!|"    { LEXTOK(OROR); }
<*>"|??!"    { LEXTOK(OROR); }
<*>"??!??!"  { LEXTOK(OROR); }
<*>"??'"     { LEXTOK(CIR); }
<*>"??!="    { LEXTOK(OR_ASSIGN); }
<*>"??'="    { LEXTOK(XOR_ASSIGN); }
<*>"??/\n"   { this->line(); LEXTOK(NL); }
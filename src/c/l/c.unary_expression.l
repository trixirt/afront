<*>"++"       { LEXTOK(INC); }
<*>"--"       { LEXTOK(DEC); }
<*>"sizeof"   { LEXTOK(SIZEOF);     }
%ifdef c11
<*>"_Alignof" { LEXTOK(_ALIGNOF); }
%endif


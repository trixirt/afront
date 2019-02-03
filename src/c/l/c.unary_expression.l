%ifndef c_start
%def c_start *
%endif

<c_start>"++"       { LEXTOK(INC); }
<c_start>"--"       { LEXTOK(DEC); }
<c_start>"sizeof"   { LEXTOK(SIZEOF);     }
%ifdef c11
<c_start>"_Alignof" { LEXTOK(_ALIGNOF); }
%endif


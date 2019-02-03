%ifndef c_start
%def c_start *
%endif

<c_start>"const"                     { LEXTOK(CONST); }
%ifdef c99
<c_start>"restrict"                  { LEXTOK(RESTRICT); }
%endif
<c_start>"volatile"                  { LEXTOK(VOLATILE);   }
%ifdef c11
<c_start>"_Atomic"                   { LEXTOK(_ATOMIC); }
%endif

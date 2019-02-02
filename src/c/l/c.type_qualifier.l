<*>"const"                     { LEXTOK(CONST); }
%ifdef c99
<*>"restrict"                  { LEXTOK(RESTRICT); }
%endif
<*>"volatile"                  { LEXTOK(VOLATILE);   }
%ifdef c11
<*>"_Atomic"                   { LEXTOK(_ATOMIC); }
%endif

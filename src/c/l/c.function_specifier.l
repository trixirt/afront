%ifdef c99
<*>"inline"                    { LEXTOK(INLINE); }
%endif
%ifdef c11
<*>"_Noreturn"                 { LEXTOK(_NORETURN) }
%endif

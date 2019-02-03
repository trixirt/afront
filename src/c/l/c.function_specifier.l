%ifndef c_start
%def c_start *
%endif

%ifdef c99
<c_start>"inline"                    { LEXTOK(INLINE); }
%endif
%ifdef c11
<c_start>"_Noreturn"                 { LEXTOK(_NORETURN) }
%endif

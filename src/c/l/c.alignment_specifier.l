%ifndef c_start
%def c_start *
%endif

%ifdef c11
<c_start>"_Alignas"                  { LEXTOK(_ALIGNAS); }
%endif

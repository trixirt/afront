%ifndef c_start
%def c_start *
%endif

<c_start>"->"             { LEXTOK(PTR); }
<c_start>"!="             { LEXTOK(NE); }
<c_start>"||"             { LEXTOK(OROR); }
<c_start>"..."            { LEXTOK(ELLIPSIS); }
%ifdef c11
<c_start>"_Generic"       { LEXTOK(_GENERIC); }
<c_start>"_Static_assert" { LEXTOK(_STATIC_ASSERT); }
%endif

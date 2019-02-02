<*>"->"             { LEXTOK(PTR); }
<*>"!="             { LEXTOK(NE); }
<*>"||"             { LEXTOK(OROR); }
<*>"..."            { LEXTOK(ELLIPSIS); }
%ifdef c11
<*>"_Generic"       { LEXTOK(_GENERIC); }
<*>"_Static_assert" { LEXTOK(_STATIC_ASSERT); }
%endif

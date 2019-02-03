%ifndef c_start
%def c_start *
%endif

<c_start>"typedef"                   { LEXTOK(TYPEDEF);    }
<c_start>"extern"                    { LEXTOK(EXTERN); }
<c_start>"static"                    { LEXTOK(STATIC);     }
%ifdef c11
<c_start>"_Thread_local"             { LEXTOK(_THREAD_LOCAL); }
%endif
<c_start>"auto"                      { LEXTOK(AUTO); }
<c_start>"register"                  { LEXTOK(REGISTER); }

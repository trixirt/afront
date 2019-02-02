<*>"typedef"                   { LEXTOK(TYPEDEF);    }
<*>"extern"                    { LEXTOK(EXTERN); }
<*>"static"                    { LEXTOK(STATIC);     }
%ifdef c11
<*>"_Thread_local"             { LEXTOK(_THREAD_LOCAL); }
%endif
<*>"auto"                      { LEXTOK(AUTO); }
<*>"register"                  { LEXTOK(REGISTER); }

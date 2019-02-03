%ifndef c_start
%def c_start *
%endif

<c_start>"<:" { LEXTOK(OBK); }
<c_start>":>" { LEXTOK(CBK); }
<c_start>"<%" { LEXTOK(OBR); }
<c_start>"%>" { LEXTOK(CBR); }

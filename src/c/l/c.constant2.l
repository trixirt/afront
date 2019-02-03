%ifndef c_start
%def c_start *
%endif

<c_start>{integer_constant}          { LEXTOK(INTEGER_CONSTANT);   }
<c_start>{floating_constant}         { LEXTOK(FLOATING_CONSTANT);  }
<c_start>{character_constant}        { LEXTOK(CHARACTER_CONSTANT); }
<c_start>{string_literal}            { LEXTOK(STRING_CONSTANT);    }

%include preamble.yy
%include c.tokens.yy
%include c.types.yy
%include directives.yy

%%

%include c.grammer.yy

%%

%include error.yy
%include override.yy
%include c.preamble.yy
%include c.tokens.yy
%include c.types.yy
%include c.directives.yy

%%

file : identifier
 {
    $$ = d->f = std::shared_ptr<pt::file> (new pt::file($1));
 }
 | file identifier
 {
    d->f->append($2);
 }
;

%include c.grammer.identifier.yy

%%

%include c.postamble.yy
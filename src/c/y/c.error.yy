void 
nada::parser::error (const location_type &loc, const std::string &msg)
{
	//   std::cerr << "Error: " << msg << " at " << loc << std::endl;
	   std::cerr << "Error: " << msg << std::endl;	
}
/*
 * Called like this..
 
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


std::string
nada::parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
{
 return "";
}

gdb of this 
$1 = {_vptr$parser = 0x4b9b60 <vtable for nada::parser+16>,
      static yypact_ninf_ = -223,
      static yytable_ninf_ = -1 '\377',
      static yypact_ = 0x4b9b90 <nada::parser::yypact_>, 
      static yydefact_ = 0x4b9e80 <nada::parser::yydefact_> "",
      static yypgoto_ = <same as static member of an already seen type>,
      static yydefgoto_ = <same as static member of an already seen type>, 
      static yytable_ = 0x4ba120 <nada::parser::yytable_>,
      static yycheck_ = <same as static member of an already seen type>,
      static yystos_ = <same as static member of an already seen type>, 
      static yyr1_ = <same as static member of an already seen type>,
      static yyr2_ = <same as static member of an already seen type>,
      static yytname_ = 0x4bc1e0 <nada::parser::yytname_>,
      yystack_ = {
        seq_ = {<std::__1::__vector_base<nada::parser::stack_symbol_type, std::__1::allocator<nada::parser::stack_symbol_type> >> = {<std::__1::__vector_base_common<true>> = {<No data fields>}, 
            __begin_ = 0x6e62a0, __end_ = 0x6e63f0, __end_cap_ = {<std::__1::__compressed_pair_elem<nada::parser::stack_symbol_type*, 0, false>> = {
            __value_ = 0x6eba20}, <std::__1::__compressed_pair_elem<std::__1::allocator<nada
	    

*/
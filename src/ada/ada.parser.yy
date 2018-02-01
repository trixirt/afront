%skeleton "lalr1.cc"
%require  "3.0.4"
%debug 
%defines
%define api.namespace {Ada}
%define api.token.prefix {ADA_}

%define parser_class_name {Parser}

%code requires {
      #include "driver.h"
}

%parse-param { Driver  *driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "driver.h"

#undef yylex
#define yylex driver->yylex
}

%define api.value.type variant
%define parse.assert

%token EOF    0     "end of file"
%token ABORT
%token ABS
%token ACCEPT
%token ACCESS
%token ALL
%token AMP
%token AND
%token ARRAY
%token ARROW
%token ASSIGN
%token AT
%token BEGIN
%token BODY
%token BOX
%token CASE
%token CHARACTER_LITERAL
%token COL
%token COM
%token CONSTANT
%token CBK
%token CPA
%token DECLARE
%token DELAY
%token DELTA
%token DIGITS
%token DO
%token DOT
%token DOTDOT
%token ELSE
%token ELSIF
%token END
%token ENTRY
%token EQ
%token EXCEPTION
%token EXIT
%token FOR
%token FUNCTION
%token GENERIC
%token GOTO
%token GT
%token GTGT
%token GTE
%token IDENTIFIER
%token IS
%token IF
%token IN
%token LIMITED
%token LOOP
%token LT
%token LTLT
%token LTE
%token MIN
%token MOD
%token MUL
%token MULMUL
%token NEW
%token NOT
%token NEQ
%token NULL
%token NUMERIC_LITERAL
%token OF
%token OBR
%token OPA
%token OR
%token OTHERS
%token OUT
%token PACKAGE
%token PLU
%token PRAGMA
%token PRIVATE
%token PROCEDURE
%token RAISE
%token RANGE
%token RECORD
%token REM
%token RENAMES
%token RETURN
%token REVERSE
%token SCO
%token SL
%token SQU
%token SELECT
%token SEPARATE
%token STRING_LITERAL
%token SUBTYPE
%token TASK
%token TERMINATE
%token THEN
%token TYPE
%token USE
%token VER
%token WHEN
%token WHILE
%token WITH
%token XOR

%locations
%start file

%%

file :
  compilation_unit_list {}
  ;	

basic_declaration :
  object_declaration            {}
| number_declaration            {}
| type_declaration              {}
| subtype_declaration           {}
| subprogram_declaration        {}
| package_declaration           {}
| task_declaration              {}
| generic_declaration           {}
| exception_declaration         {}
| generic_instantiation         {}
| renaming_declaration          {}
| deferred_constant_declaration {}
;

object_declaration :
  identifier_list COL subtype_indication SCO {}
| identifier_list COL subtype_indication ASSIGN expression SCO {}
| identifier_list COL CONSTANT subtype_indication ASSIGN expression SCO {}
| identifier_list COL CONSTANT constrained_array_definition ASSIGN expression SCO {}
;

universal_static_expression :
  expression {}
  ;
  
number_declaration :
  identifier_list COL CONSTANT ASSIGN universal_static_expression SCO {}
  ;

identifier_list :
  IDENTIFIER {}
| identifier_list COM IDENTIFIER {}
;

type_declaration :
  full_type_declaration {}
| incomplete_type_declaration {}
| private_type_declaration {}
;

full_type_declaration :
  TYPE IDENTIFIER IS type_definition SCO {}
| TYPE IDENTIFIER discriminant_part IS type_definition SCO {}
;

type_definition :
  enumeration_type_definition {}
| integer_type_definition {}
| real_type_definition {}
| array_type_definition {}
| record_type_definition {}
| access_type_definition {}
| derived_type_definition {}
;

subtype_declaration :
  SUBTYPE IDENTIFIER IS subtype_indication SCO {}
  ;

subtype_indication :
  name { }
| name constraint { }
;
  
constraint :
  range_constraint {}
| floating_point_constraint {}
| fixed_point_constraint {}
| index_constraint {}
| discriminant_constraint {}
;

derived_type_definition :
  NEW subtype_indication {}
  ;

range_constraint :
  range range {}
  ;

range_attribute :
  attribute {}
  ;
  
range :
  range_attribute {}
| simple_expression DOTDOT simple_expression {}
;


enumeration_type_definition :
  OPA enumeration_literal_specification_list CPA {}

enumeration_literal_specification_list :
  enumeration_literal_specification {}
| enumeration_literal_specification_list COM enumeration_literal_specification {}

enumeration_literal_specification :
  enumeration_literal {}

enumeration_literal :
  IDENTIFIER {}
| CHARACTER_LITERAL {}

integer_type_definition :
  range_constraint {}

real_type_definition :
  floating_point_constraint {}
| fixed_point_constraint {}

floating_point_constraint :
  floating_accuracy_definition {}
| floating_accuracy_definition range_constraint {}

static_simple_expression :
  simple_expression {}
  
floating_accuracy_definition :
  DIGITS static_simple_expression {}

fixed_point_constraint :
  fixed_accuracy_definition {}
  fixed_accuracy_definition range_constraint {}

fixed_accuracy_definition :
  DELTA static_simple_expression {}

array_type_definition :
  unconstrained_array_definition {}
| constrained_array_definition {}

unconstrained_array_definition :
  ARRAY OPA index_subtype_definition_list CPA OF component_subtype_definition
  
index_subtype_definition_list :
  index_subtype_definition {}
| index_subtype_definition_list COM index_subtype_definition {}

constrained_array_definition :
  ARRAY index_constraint OF component_subtype_definition {}

index_subtype_definition :
  name range BOX {}

index_constraint :
  OPA discrete_range_list CPA {}

discrete_range_list :
  discrete_range {}
| discrete_range_list COM discrete_range {}

discrete_range :
  subtype_indication {}
| range {}

record_type_definition :
  RECORD component_list END RECORD {} 

component_list :
  component_declaration {}
| component_declaration variant_part {}
| component_list component_declaration {}
| component_list component_declaration variant_part {}
| NULL SCO 

component_declaration :
  identifier_list COL component_subtype_definition SCO
  identifier_list COL component_subtype_definition ASSIGN expression SCO 

component_subtype_definition :
  subtype_indication {}

discriminant_part :
  OPA discriminant_specification_list CPA {}
  
discriminant_specification_list :
  discriminant_specification {}
| discriminant_specification_list SCO discriminant_specification {}

discriminant_specification :
  identifier_list COL name {}
| identifier_list COL name ASSIGN expression {}

discriminant_constraint :
  OPA discriminant_association_list CPA {}

discriminant_association_list :
  discriminant_association {}
| discriminant_association_list COM discriminant_association_list {}

discriminant_simple_name :
  simple_name {}

discriminant_simple_name_list :
  discriminant_simple_name {}
| discriminant_simple_name_list VER discriminant_simple_name {}

discriminant_association :
  expression
| discriminant_simple_name_list ARROW expression
       
variant_part :
  CASE discriminant_simple_name IS variant_list END CASE SCO

variant_list :
  variant {}
| variant_list variant {}

variant :
 WHEN choice_list ARROW component_list {}

choice_list :
  choice {}
| choice_list VER choice {}
;

component_simple_name :
  simple_name {}
;

choice :
  simple_expression {}
| discrete_range {}
| OTHERS {}
| component_simple_name {}
;

access_type_definition :
  ACCESS subtype_indication {}
;

incomplete_type_declaration :
  TYPE IDENTIFIER SCO {}
| TYPE IDENTIFIER discriminant_part SCO {}
;

declarative_part :
 basic_declarative_item {}
| later_declarative_item {}
| basic_declarative_item later_declarative_item {} 
;

basic_declarative_item :
  basic_declaration {}
| representation_clause {}
| use_clause {}
;

later_declarative_item :
  body {}
| generic_declaration {}
| generic_instantiation {}
| package_declaration {}
| subprogram_declaration {}
| task_declaration       {}
| use_clause             {}
;

body :
  proper_body {}
| body_stub {}
;

proper_body :
  subprogram_body {}
| package_body {}
| task_body {}
;

name :
  attribute {}
| CHARACTER_LITERAL {}
| operator_symbol {}
| indexed_component  {}
| selected_component {}
| simple_name {}
| slice {}
;

simple_name :
  IDENTIFIER {} 
;

prefix :
  name {}
| function_call {}
;

indexed_component :
  prefix OPA expression_list CPA {}
;

expression_list :
  expression {}
| expression_list COM expression {}
;

slice :
  prefix OPA discrete_range CPA
;

selected_component :
  prefix DOT selector {}
;

selector :
  simple_name {}
| CHARACTER_LITERAL {}
| operator_symbol {}
| ALL {}                                                     
;

attribute :
  prefix SQU attribute_designator {} 
;

attribute_designator :
  simple_name {}
|  simple_name OPA universal_static_expression CPA
;

component_association_list :
  component_association {}
| component_association_list COM component_association {}
;

aggregate :
  OPA component_association_list CPA {}
  ;

choice_list :
  choice {}
| choice_list VER choice {}
;

component_association :
  choice_list ARROW expression {}
  ;

expression :
  relation {}
| relation AND relation {}
| relation AND THEN relation {}
| relation OR relation {}
| relation OR ELSE relation {}
| relation XOR relation {}
;

relation :
  simple_expression {}
| simple_expression relational_operator simple_expression {}
| simple_expression IN range {}
| simple_expression NOT IN range {}
| simple_expression IN name {}
| simple_expression NOT IN name {}
;

simple_expression :
 term {}
| unary_adding_operator term {}
| term binary_adding_operator term {}
| unary_adding_operator term binary_adding_operator term {}
;

term :
  factor {}
| factor multiplying_operator factor {}
;

factor :
  primary {}
| primary MULMUL primary {}
| ABS primary {}
| NOT primary {}
;

primary :
  NUMERIC_LITERAL {}
| NULL {}
| aggregate {}
| STRING_LITERAL {}
| name {}
| allocator {}
| function_call {}
| type_conversion {}
| qualified_expression {}
| OPA expression CPA {}
;

relational_operator :
  EQ {}
| NEQ {}
| LT {}
| LTE {}
| GT {}
| GTE {}
;

binary_adding_operator :
  PLU {}
| MIN {}
| AMP {}
;

unary_adding_operator :
  PLU {}
| MIN {}
;

multiplying_operator :
  MUL {}
| SL {}
| MOD {}
| REM {}
;

type_conversion :
  name OPA expression CPA {}
  ;

qualified_expression :
  name SQU OPA expression CPA {}
| name SQU aggregate {}
;

allocator :
  NEW subtype_indication {}
| NEW qualified_expression {}
;

sequence_of_statements :
  statement_list {}
  ;

statement_list :
  statement {}
| statement_list statement {}
;

statement :
  simple_statement {}
| label simple_statement {}
| compound_statement {}
| label compound_statement {}
;

simple_statement :
  null_statement {}
| assignment_statement {}
| procedure_call_statement {}
| exit_statement {}
| return_statement {}
| goto_statement {}
| entry_call_statement {}
| delay_statement {}
| abort_statement {}
| raise_statement {}
| code_statement {}
;

compound_statement :
  if_statement {}
| case_statement {}
| loop_statement {}
| block_statement {}
| accept_statement {}
| select_statement {}
;

label_simple_name :
  simple_name {}
  ;
  
label :
  LTLT label_simple_name GTGT {}
  ;

null_statement :
  NULL SCO
  ;

assignment_statement :
  name ASSIGN expression SCO {}
  ;

if_statement :
  IF condition THEN sequence_of_statements END IF SCO {}
| IF condition THEN sequence_of_statements ELSE END sequence_of_statements IF SCO {}
| IF condition THEN sequence_of_statements elsif_list END IF SCO {}
| IF condition THEN sequence_of_statements elsif_list ELSE END sequence_of_statements IF SCO {}
;

elsif :
  ELSIF condition THEN sequence_of_statements {}
  ;

elsif_list :
  elsif {} 
| elsif_list elsif {}
;

boolean_expression :
  expression {}
  ;
  
condition :
  boolean_expression {}
  ;

case_statement :
  CASE expression IS case_statement_alternative_list END CASE SCO {}
  ;

case_statement_alternative_list :
  case_statement_alternative {}
| case_statement_alternative_list case_statement_alternative {}
;

case_statement_alternative :
  WHEN choice_list ARROW sequence_of_statements {}
  ;

loop_simple_name :
  simple_name {}
  ;
  
loop_statement :
  LOOP sequence_of_statements END LOOP SCO {}
| iteration_scheme LOOP sequence_of_statements END LOOP SCO {}
| loop_simple_name COL LOOP sequence_of_statements END LOOP loop_simple_name SCO {}
| loop_simple_name COL iteration_scheme LOOP sequence_of_statements END LOOP loop_simple_name SCO {}
;

iteration_scheme :
  WHILE condition {}
| FOR loop_parameter_specification {}
;

loop_parameter_specification :
  IDENTIFIER IN discrete_range {}
| IDENTIFIER IN REVERSE discrete_range {}
;

exception_handler_list :
  exception_handler {}
| exception_handler_list exception_handler
;

block_simple_name :
  simple_name {}
  ;
  
block_statement :
  BEGIN sequence_of_statements END SCO {}
|  DECLARE declarative_part BEGIN sequence_of_statements END SCO {}
|  block_simple_name COL BEGIN sequence_of_statements END block_simple_name SCO {}
|  block_simple_name DECLARE declarative_part BEGIN sequence_of_statements END block_simple_name SCO {}
|  BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
|  DECLARE declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
|  block_simple_name COL BEGIN sequence_of_statements EXCEPTION exception_handler_list END block_simple_name SCO {}
|  block_simple_name DECLARE declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END block_simple_name SCO {}
;

loop_name :
  name {}
  ;
  
exit_statement :
  EXIT SCO {}
| EXIT loop_name SCO {}
| EXIT WHEN condition SCO {}
| EXIT loop_name WHEN condition SCO {}
;

return_statement :
  RETURN SCO {}
| RETURN expression SCO {}
;

goto_statement :
  GOTO name SCO {}
  ;

subprogram_declaration :
  subprogram_specification SCO {}
  ;

subprogram_specification :
  PROCEDURE IDENTIFIER {}
| PROCEDURE IDENTIFIER formal_part {}
| FUNCTION designator RETURN name {}
| FUNCTION designator formal_part RETURN name {}
;

designator :
  IDENTIFIER {}
| operator_symbol {}
;

operator_symbol :
  STRING_LITERAL {}
  ;

parameter_specification_list :
  parameter_specification {}
| parameter_specification_list SCO parameter_specification {}
;

formal_part :
  OPA parameter_specification_list CPA {}
  ;

parameter_specification :
  identifier_list : name {}
| identifier_list : mode name {}
| identifier_list : name ASSIGN expression {}
| identifier_list : mode name ASSIGN expression {}
;

mode :
  IN {}
| IN OUT {}
| OUT {}
;

subprogram_body :
  subprogram_specification IS BEGIN sequence_of_statements END SCO {}
| subprogram_specification IS declarative_part BEGIN sequence_of_statements END SCO {}
| subprogram_specification IS BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
| subprogram_specification IS declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
| subprogram_specification IS BEGIN sequence_of_statements END designator SCO {}
| subprogram_specification IS declarative_part BEGIN sequence_of_statements END designator SCO {}
| subprogram_specification IS BEGIN sequence_of_statements EXCEPTION exception_handler_list END designator SCO {}
| subprogram_specification IS declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END designator SCO {}
;

procedure_call_statement :
  name SCO {}
  name actual_parameter_part SCO {}
  ;

function_call :
  name SCO {}
| name actual_parameter_part SCO {}
;

parameter_association_list :
  parameter_association {}
| parameter_association_list COM parameter_association {}
;
  
actual_parameter_part :
  OPA parameter_association_list CPA
  ;

parameter_association :
  actual_parameter {}
| formal_parameter ARROW actual_parameter {}
;

parameter_simple_name :
  simple_name {}
  ;
  
formal_parameter :
  parameter_simple_name {}
  ;

actual_parameter :
  expression {}
  name {}
  name OPA name CPA {}
  ;

package_declaration :
  package_specification SCO {}
  ;

package_simple_name :
  simple_name {}
  ;

package_specification :
  PACKAGE IDENTIFIER IS END {}
| PACKAGE IDENTIFIER IS END package_simple_name {}
| PACKAGE IDENTIFIER IS basic_declarative_item END {}
| PACKAGE IDENTIFIER IS basic_declarative_item END package_simple_name {}
| PACKAGE IDENTIFIER IS PRIVATE basic_declarative_item END {}
| PACKAGE IDENTIFIER IS PRIVATE basic_declarative_item END package_simple_name {}
| PACKAGE IDENTIFIER IS basic_declarative_item PRIVATE basic_declarative_item END {}
| PACKAGE IDENTIFIER IS basic_declarative_item PRIVATE basic_declarative_item END package_simple_name {}
;

package_body :
  PACKAGE BODY package_simple_name IS END SCO {}
| PACKAGE BODY package_simple_name IS END package_simple_name SCO {}
| PACKAGE BODY package_simple_name IS declarative_part END SCO {}
| PACKAGE BODY package_simple_name IS declarative_part END package_simple_name SCO {}
| PACKAGE BODY package_simple_name IS BEGIN sequence_of_statements END SCO {}
| PACKAGE BODY package_simple_name IS BEGIN sequence_of_statements END package_simple_name SCO {}
| PACKAGE BODY package_simple_name IS declarative_part BEGIN sequence_of_statements END SCO {}
| PACKAGE BODY package_simple_name IS declarative_part BEGIN sequence_of_statements END package_simple_name SCO {}
| PACKAGE BODY package_simple_name IS BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
| PACKAGE BODY package_simple_name IS BEGIN sequence_of_statements EXCEPTION exception_handler_list END package_simple_name SCO {}
| PACKAGE BODY package_simple_name IS declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
| PACKAGE BODY package_simple_name IS declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END package_simple_name SCO {}
;

private_type_declaration :
  TYPE IDENTIFIER [discriminant_part] IS PRIVATE SCO {}
| TYPE IDENTIFIER discriminant_part IS PRIVATE SCO {}
| TYPE IDENTIFIER [discriminant_part] IS LIMITED PRIVATE SCO {}
| TYPE IDENTIFIER discriminant_part IS LIMITED PRIVATE SCO {}
;

deferred_constant_declaration :
  identifier_list COL CONSTANT name SCO {}
  ;

package_name_list :
  name {}
| package_name_list COM name {}
;

use_clause :
  USE package_name_list SCO {}
  ;

exception_name :
  name {}
  ;
  
renaming_declaration :
  IDENTIFIER COL name RENAMES name SCO {}
| IDENTIFIER COL EXCEPTION RENAMES exception_name SCO {}
| PACKAGE IDENTIFIER RENAMES name SCO {}
| subprogram_specification RENAMES name SCO {}
;

task_declaration :
  task_specification SCO {}
  ;

task_simple_name :
  simple_name {}
  ;
  
task_specification :
  TASK IDENTIFIER {}
| TASK TYPE IDENTIFIER {}
| TASK IDENTIFIER IS END {}
| TASK TYPE IDENTIFIER IS END {}
| TASK IDENTIFIER IS END task_simple_name {}
| TASK TYPE IDENTIFIER IS END task_simple_name {}
| TASK IDENTIFIER IS entry_declaration END {}
| TASK TYPE IDENTIFIER IS entry_declaration END {}
| TASK IDENTIFIER IS entry_declaration END task_simple_name {}
| TASK TYPE IDENTIFIER IS entry_declaration END task_simple_name {}
| TASK IDENTIFIER IS representation_clause END {}
| TASK TYPE IDENTIFIER IS representation_clause END {}
| TASK IDENTIFIER IS representation_clause END task_simple_name {}
| TASK TYPE IDENTIFIER IS representation_clause END task_simple_name {}
| TASK IDENTIFIER IS entry_declaration representation_clause END {}
| TASK TYPE IDENTIFIER IS entry_declaration representation_clause END {}
| TASK IDENTIFIER IS entry_declaration representation_clause END task_simple_name {}
| TASK TYPE IDENTIFIER IS entry_declaration representation_clause END task_simple_name {}
;

task_body :
  TASK BODY task_simple_name IS BEGIN sequence_of_statements END SCO {}
| TASK BODY task_simple_name IS BEGIN sequence_of_statements END task_simple_name SCO {}
| TASK BODY task_simple_name IS declarative_part BEGIN sequence_of_statements END SCO {}
| TASK BODY task_simple_name IS declarative_part BEGIN sequence_of_statements END task_simple_name SCO {}
| TASK BODY task_simple_name IS BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
| TASK BODY task_simple_name IS BEGIN sequence_of_statements EXCEPTION exception_handler_list END task_simple_name SCO {}
| TASK BODY task_simple_name IS declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END SCO {}
| TASK BODY task_simple_name IS declarative_part BEGIN sequence_of_statements EXCEPTION exception_handler_list END task_simple_name SCO {}
;

entry_declaration :
  ENTRY IDENTIFIER SCO {}
| ENTRY IDENTIFIER OPA discrete_range CPA SCO {}
| ENTRY IDENTIFIER formal_part SCO {}
| ENTRY IDENTIFIER OPA discrete_range CPA formal_part SCO {}
;

entry_call_statement :
  name SCO {}
| name actual_parameter_part SCO {}
;

entry_simple_name :
  simple_name {}
  ;
  
accept_statement :
  ACCEPT entry_simple_name SCO {}
| ACCEPT entry_simple_name OPA entry_index CPA SCO {}
| ACCEPT entry_simple_name formal_part SCO {}
| ACCEPT entry_simple_name OPA entry_index CPA formal_part SCO {}
| ACCEPT entry_simple_name DO sequence_of_statements END SCO {}
| ACCEPT entry_simple_name OPA entry_index CPA DO sequence_of_statements END SCO {}
| ACCEPT entry_simple_name formal_part DO sequence_of_statements END SCO {}
| ACCEPT entry_simple_name OPA entry_index CPA formal_part DO sequence_of_statements END SCO {}
| ACCEPT entry_simple_name DO sequence_of_statements END entry_simple_name SCO {}
| ACCEPT entry_simple_name OPA entry_index CPA DO sequence_of_statements END entry_simple_name SCO {}
| ACCEPT entry_simple_name formal_part DO sequence_of_statements END entry_simple_name SCO {}
| ACCEPT entry_simple_name OPA entry_index CPA formal_part DO sequence_of_statements END entry_simple_name SCO {}
;

entry_index :
  expression {}
  ;

delay_statement :
  DELAY simple_expression SCO {}
  ;

select_statement :
  selective_wait {}
| conditional_entry_call {}
| timed_entry_call {}
;

or_select_alternative_list :
  OR select_alternative {}
| or_select_alternative_list OR select_alternative {}
;
  
selective_wait :
  SELECT select_alternative END SELECT SCO {}
| SELECT select_alternative or_select_alternative_list END SELECT SCO {}
| SELECT select_alternative ELSE sequence_of_statements END SELECT SCO {}
| SELECT select_alternative or_select_alternative_list ELSE sequence_of_statements END SELECT SCO {}
;

select_alternative :
  selective_wait_alternative {}
|  WHEN condition ARROW selective_wait_alternative {}
;

selective_wait_alternative :
  accept_alternative {}
| delay_alternative {}
| terminate_alternative {}
;

accept_alternative :
  accept_statement {}
| accept_statement sequence_of_statements {}
;

delay_alternative :  
  delay_statement {}
| delay_statement sequence_of_statements {}
;

terminate_alternative :
 TERMINATE SCO {}
 ;

conditional_entry_call :
  SELECT entry_call_statement ELSE sequence_of_statements END SELECT SCO {}
| SELECT entry_call_statement sequence_of_statements ELSE sequence_of_statements END SELECT SCO {}
;

timed_entry_call :
  SELECT entry_call_statement OR delay_alternative END SELECT SCO {}
  SELECT entry_call_statement sequence_of_statements OR delay_alternative END SELECT SCO {}
  ;

task_name :
  name {}
  ;
  
task_name_list :
  task_name {}
| task_name_list COM task_name {}
;

abort_statement :
  ABORT task_name_list SCO {}
  ;

compilation_unit_list :
  compilation_unit {}
| compilation_unit_list compilation_unit {}
;

compilation_unit :
  context_clause library_unit {}
| context_clause secondary_unit {}
;

library_unit :
  subprogram_declaration {}
| package_declaration {}
| generic_declaration {}
| generic_instantiation {}
| subprogram_body {}
;

secondary_unit :
  library_unit_body {}
| subunit {}
;

library_unit_body :
  subprogram_body {}
| package_body {}
;

with_or_use_clause :
  with_clause {}
| with_clause use_clause {}
;

with_or_use_clause_list :
  with_or_use_clause {}
| with_or_use_clause_list with_or_use_clause {}
;

context_clause :
  with_or_use_clause_list {}
  ;

unit_simple_name :
  simple_name {}
  ;
  
unit_simple_name_list :
  unit_simple_name {}
| unit_simple_name_list COM unit_simple_name {}
;

with_clause :
 unit_simple_name_list SCO
 ;

body_stub :
  subprogram_specification IS SEPARATE SCO {}
| PACKAGE BODY package_simple_name IS SEPARATE SCO {}
| TASK BODY task_simple_name IS SEPARATE SCO {}
;

parent_unit_name :
  name {}
  ;
  
subunit :
  SEPARATE OPA parent_unit_name CPA proper_body {}
  ;

exception_declaration :
  identifier_list COL EXCEPTION SCO {}
  ;

exception_handler :
  WHEN exception_choice_list ARROW sequence_of_statements {}
  ;

exception_choice :
  exception_name {}
| OTHERS {}
;

exception_choice_list :
  exception_choice {}
| exception_choice_list  exception_choice {}
;

raise_statement :
  RAISE SCO {}
| RAISE SCO exception_name SCO {}
;

generic_declaration :
  generic_specification SCO {}
  ;

generic_specification :
  generic_formal_part subprogram_specification {}
| generic_formal_part package_specification {}
;

generic_parameter_declaration_list :
  generic_parameter_declaration {}
| generic_parameter_declaration_list generic_parameter_declaration {}
;

generic_formal_part :
  GENERIC generic_parameter_declaration_list
  ;

generic_parameter_declaration :
  identifier_list COL name SCO {}
| identifier_list COL IN name SCO {}
| identifier_list COL OUT name SCO {}
| identifier_list COL IN OUT name SCO {}
| identifier_list COL name ASSIGN expression SCO {}
| identifier_list COL IN name ASSIGN expression SCO {}
| identifier_list COL OUT name ASSIGN expression SCO {}
| identifier_list COL IN OUT name ASSIGN expression SCO {}
| TYPE IDENTIFIER IS generic_type_definition SCO {}
| private_type_declaration {}
| WITH subprogram_specification SCO {}
| WITH subprogram_specification IS name SCO {}
| WITH subprogram_specification IS BOX SCO {}
;

generic_type_definition :
  OPA BOX CPA {}
| RANGE BOX {}
| DIGITS BOX {}
| DELTA BOX {}
| array_type_definition {}
| access_type_definition {}
;

generic_association_list :
  generic_association {}
| generic_association_list COM generic_association {}
;

generic_actual_part :
  OPA generic_association_list CPA {}
  ;

generic_instantiation :
  PACKAGE IDENTIFIER IS NEW name SCO {}
| PACKAGE IDENTIFIER IS NEW name generic_actual_part SCO {}
| PROCEDURE IDENTIFIER IS NEW name SCO {}
| PROCEDURE IDENTIFIER IS NEW name generic_actual_part SCO {}
| FUNCTION designator IS NEW name SCO {}
| FUNCTION designator IS NEW name generic_actual_part SCO {}
;

generic_association :
  generic_actual_parameter {}
| generic_formal_parameter ARROW generic_actual_parameter {}
;

generic_formal_parameter :
  parameter_simple_name {}
| operator_symbol {}
;

generic_actual_parameter :
  expression {}
;

representation_clause :
  type_representation_clause {}
| address_clause {}
;

type_representation_clause :
  length_clause {}
| enumeration_representation_clause {}
| record_representation_clause {}
;

length_clause :
  FOR attribute USE simple_expression SCO {}
  ;

type_simple_name :
  simple_name {}
  ;
  
enumeration_representation_clause :
  FOR type_simple_name USE aggregate SCO {}
  ;

record_representation_clause :
  FOR type_simple_name USE RECORD END RECORD SCO {}
  FOR type_simple_name USE RECORD alignment_clause END RECORD SCO {}
  FOR type_simple_name USE RECORD END component_clause RECORD SCO {}
  FOR type_simple_name USE RECORD alignment_clause component_clause END RECORD SCO {}
  ;

alignment_clause :
  AT MOD static_simple_expression SCO {}
  ;

static_range :
  range {}
  ;

component_clause :
  name AT static_simple_expression RANGE static_range SCO {}
  ;

address_clause :
  FOR simple_name USE AT simple_expression SCO {}
  ;

code_statement :
  name SQU aggregate SCO {}
  ;
      
%%


void 
Ada::Parser::error (const location_type &loc, const std::string &msg)
{
   std::cerr << "Error: " << msg << " at " << loc << std::endl;
}
 
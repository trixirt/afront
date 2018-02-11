#!/bin/sh

set -x

if [ x$1 = x ]; then
    echo "Need an argument"
    exit 1
fi
HERE=`dirname $0`
HERE=`realpath $HERE`
D=`realpath $1`
if [ ! -d $D ]; then
    echo "Need a directory name in $1"
    exit 1
fi

F=`basename $1`
if [ x$F = x ]; then
    echo "Need a file name in $1"
    exit 1
fi
U=`echo -n $F | tr /a-z/ /A-Z/`

cd $D

H=${F}.h
V=${F}.cpp

C="abstract_array_declarator
abstract_declarator
abstract_function_declarator
additive_expr
alignment_specifier
and_expr
argument_expr_list
array_declarator
assignment_expr
assignment_operator
atomic_type_specifier
cast_expr
compound_statement
conditional_expr
constant_expr
declaration
declaration_list
declaration_specifiers
declarator
direct_abstract_declarator
direct_declarator
enumerator
enumerator_list
enum_specifier
equality_expr
exclusive_or_expr
expr
expression_statement
external_definition
function_body
function_declarator
function_definition
function_specifier
generic_association
generic_assoc_list
generic_selection
identifier
identifier_list
inclusive_or_expr
init_declarator
init_declarator_list
initializer
initializer_list
iteration_statement
jump_statement
labeled_statement
logical_and_expr
logical_or_expr
multiplicative_expr
m
n
parameter_declaration
parameter_list
parameter_type_list
pointer
postfix_expr
primary_expr
relation_expr
selection_statement
shift_expr
specifier_qualifier_list
statement
statement_list
storage_class_specifier
struct_declaration
struct_declaration_list
struct_declarator
struct_declarator_list
struct_or_union
struct_or_union_specifier
translation_unit
type_name
type_qualifier
type_qualifier_list
type_specifier
typedef_name
unary_expr
unary_operator"

T="
identifier
struct_or_union
unary_operator"

cat ${HERE}/../../../../COPYRIGHT > $H
cat ${HERE}/../../../../COPYRIGHT > $V

echo "#ifndef NADA_C_PT_VIS_${U}_H" >> $H
echo "#define NADA_C_PT_VIS_${U}_H" >> $H
echo "#include \"parser.tab.hh\""   >> $H
echo "#include \"../visitor.h\""    >> $H
echo "class $F : public visitor {"  >> $H
echo "public:"                      >> $H
echo "$F ();"                       >> $H
echo "virtual ~$F ();"              >> $H
for c in $C; do
    echo "virtual void v($c *a);"   >> $H
done
echo "private:"                     >> $H
echo "};"                           >> $H
echo "#endif"                       >> $H

echo "#include \"$H\""              >> $V
echo "#include \"e.h\""             >> $V
echo "#include \"pt.h\""            >> $V
echo "${F}::$F () {}"               >> $V
echo "${F}::~$F () {}"              >> $V

for c in $C; do
    echo "void ${F}::v($c *a)   {"                          >> $V
    if [ $c = nl ]; then
	echo "for (auto c : a->get()) { c->accept(this); }" >> $V
    else
	is_term=0
	for t in $T; do
	    if [ $c = $t ]; then
		is_term=1
	    fi
	done
	if [ x$is_term = x0 ]; then
	    echo "a->caccept(this);"                            >> $V
	fi
    fi
    echo "}"                                                >> $V
    echo ""                                                 >> $V
done

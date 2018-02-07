#!/bin/sh

set -x

AR=ar
CC="ccache clang"
CXX="ccache clang++"
#CXX="clang++"
AFL_CC="afl-clang"
AFL_CXX="afl-clang++"

CXX_STD=c++17
CXXFLAGS="-frtti -fno-limit-debug-info"
#CXXFLAGS="$CXXFLAGS -DWARNING_TRAINING"

# CXX=$AFL_CXX
# CXXFLAGS="-static -no-integrated-as -DWARNING_TRAINING -DABORT_TRAINING"

FORMAT=clang-format
	
cd ..
TOP=$PWD
SRC=$PWD/src
OBJ=$TOP/obj
LIB=$TOP/lib
TOOLS=$TOP/tools/install
LEX=$TOOLS/bin/flex
YACC=$TOOLS/bin/bison
# For debugging
# YACC_FLAGS=-t
LYPP=$TOOLS/bin/lypp
LYPP_FLAGS="-DDEBUG"
CXXFLAGS="$CXXFLAGS -std=$CXX_STD -I${SRC} -I${TOOLS}/include -I${OBJ} -g -O0"
CINCLUDES="-I${SRC}/c -I${SRC}/c/pt -I${SRC}/l -I${SRC}/c/l -I${OBJ}/c -I${SRC}/pt -I${SRC}/at"
FIGINCLUDES="-I${SRC}/fig -I${SRC}/fig/pt -I${SRC}/l -I${SRC}/fig/l -I${OBJ}/fig -I${SRC}/pt -I${SRC}/at"
CLIBS=

mkdir -p ${OBJ}/at
mkdir -p ${OBJ}/ada
mkdir -p ${OBJ}/c/pt/v/pa
mkdir -p ${OBJ}/c/pt/v/cg
mkdir -p ${OBJ}/c/pt/v/chk
mkdir -p ${OBJ}/c/pt/v/scope
mkdir -p ${OBJ}/c/pt/v/typedefs
mkdir -p ${OBJ}/con
mkdir -p ${OBJ}/fig/pt
mkdir -p ${OBJ}/pt

cd ${OBJ}

OBJS=
C_OBJS=
ADA_OBJS=



AT="ast scope type"
AT_OBJS=
for at in $AT; do
    f=at/${at}.o
    if [ -f $f ]; then
	rm $f
    fi
    $CXX $CXXFLAGS $CINCLUDES -c ${SRC}/at/${at}.cpp -o ${f}
    if [ ! -f $f ]; then
	echo "Failed to build $f"
	exit 1
    fi
    AT_OBJS="$f $AT_OBJS"
done 

if [ -f libat.a ]; then
    rm libat.a
fi
$AR cr libat.a $AT_OBJS
if [ ! -f libat.a ]; then
    echo "Failed to build libat.a"
    exit 1
fi

CLIBS="$CLIBS -L${OBJ} -lat"
cd ${OBJ}
AT_OBJS=


PT="n"
PT_OBJS=
for pt in $PT; do
    f=pt/${pt}.o
    if [ -f $f ]; then
	rm $f
    fi
    $CXX $CXXFLAGS $INCLUDES -c ${SRC}/pt/${pt}.cpp -o ${f}
    if [ ! -f $f ]; then
	echo "Failed to build $f"
	exit 1
    fi
    PT_OBJS="$f $PT_OBJS"
done 

if [ -f libpt.a ]; then
    rm libpt.a
fi
$AR cr libpt.a $PT_OBJS
if [ ! -f libpt.a ]; then
    echo "Failed to build libpt.a"
    exit 1
fi

CLIBS="$CLIBS -L${OBJ} -lpt"
cd ${OBJ}
PT_OBJS=

cd fig

$LYPP -I $SRC/fig/y $LYPP_FLAGS $SRC/fig/y/fig.parser.yy > parser.yy
$YACC $YACC_FLAGS -d -v parser.yy

if [ ! -f parser.tab.cc ]; then
    exit 1
fi
if [ -f parser.o ]; then
    rm parser.o
fi
$CXX $CXXFLAGS $FIGINCLUDES -c parser.tab.cc -o parser.o
if [ ! -f parser.o ]; then
    echo "Problem building parser"
    exit 1
fi
exit
C_OBJS="fig/parser.o $C_OBJS"


PT="pt"
PT_OBJS=
for pt in $PT; do
    f=pt/${pt}.o
    if [ -f $f ]; then
	rm $f
    fi
    $CXX $CXXFLAGS $CINCLUDES -c ${SRC}/fig/pt/${pt}.cpp -o ${f}
    if [ ! -f $f ]; then
	echo "Failed to build $f"
	exit 1
    fi
    PT_OBJS="$f $PT_OBJS"
done 

if [ -f libfigpt.a ]; then
    rm libfigpt.a
fi
$AR cr libfigpt.a $PT_OBJS
if [ ! -f libfigpt.a ]; then
    echo "Failed to build libcpt.a"
    exit 1
fi
CLIBS="-L${OBJ}/fig -lfigpt $CLIBS"

cd ..

cd c
if [ -f parser.tab.cc ]; then
    rm parser.tab.*
    rm stack.hh
fi

$LYPP -I $SRC/c/y $LYPP_FLAGS -Dc99 -Dc11 $SRC/c/y/c.parser.yy > parser.yy
$YACC $YACC_FLAGS -d -v parser.yy

if [ -f parser.tab.hh ]; then
    sed -e "s#location.hh#$PWD/location.hh#" < parser.tab.hh > parser.tab.hh.s
    #  sed -e "/location.hh/d" < parser.tab.hh > parser.tab.hh.s
    sed -e "s#stack.hh#$PWD/stack.hh#" < parser.tab.hh.s > parser.tab.hh
    sed -e "s#private:#public:#g" < parser.tab.hh > parser.tab.hh.s
    mv parser.tab.hh.s parser.tab.hh
else
    exit 1
fi

if [ ! -f parser.tab.cc ]; then
    exit 1
fi
if [ -f parser.o ]; then
    rm parser.o
fi
$CXX $CXXFLAGS $CINCLUDES -c parser.tab.cc -o parser.o
if [ ! -f parser.o ]; then
    echo "Problem building parser"
    exit 1
fi

C_OBJS="c/parser.o $C_OBJS"

if [ -f c.lexer.yy.cc ]; then
    rm c.lexer.yy.cc
fi
$LYPP -I $SRC/c/l $LYPP_FLAGS $SRC/c/l/c.lexer.l > c.lexer.l
$LEX --outfile=c.lexer.yy.cc c.lexer.l
if [ ! -f c.lexer.yy.cc ]; then
    exit 1
fi
if [ -f c.lexer.o ]; then
    rm c.lexer.o
fi

$CXX $CXXFLAGS $CINCLUDES -E c.lexer.yy.cc > c.lexer.ii
$CXX $CXXFLAGS $CINCLUDES -c c.lexer.yy.cc -o c.lexer.o
if [ ! -f c.lexer.o ]; then
    exit 1
fi

C_OBJS="c/c.lexer.o $C_OBJS"

PT="abstract_array_declarator direct_abstract_declarator abstract_declarator
    abstract_function_declarator additive_expr and_expr argument_expr_list
    array_declarator assignment_expr assignment_operator cast_expr
    compound_statement conditional_expr constant_expr declaration
    declaration_list declaration_specifiers direct_declarator declarator enumerator
    enumerator_list enum_specifier equality_expr exclusive_or_expr expr
    expression_statement external_definition translation_unit function_body
    function_declarator function_definition function_specifier 
    generic_association generic_assoc_list generic_selection identifier identifier_list
    inclusive_or_expr init_declarator init_declarator_list initializer
    initializer_list iteration_statement jump_statement labeled_statement
    logical_and_expr logical_or_expr multiplicative_expr n
    parameter_declaration parameter_list
    parameter_type_list pointer postfix_expr primary_expr relation_expr
    selection_statement specifier_qualifier_list shift_expr statement statement_list
    storage_class_specifier struct_declaration struct_declaration_list
    struct_declarator struct_declarator_list struct_or_union
    struct_or_union_specifier type_name type_qualifier type_qualifier_list
    typedef_name type_specifier 
    unary_expr unary_operator"
PT_OBJS=
for pt in $PT; do
    f=pt/${pt}.o
    if [ -f $f ]; then
	rm $f
    fi
    $CXX $CXXFLAGS $CINCLUDES -c ${SRC}/c/pt/${pt}.cpp -o ${f}
    if [ ! -f $f ]; then
	echo "Failed to build $f"
	exit 1
    fi
    PT_OBJS="$f $PT_OBJS"
done 

if [ -f libcpt.a ]; then
    rm libcpt.a
fi
$AR cr libcpt.a $PT_OBJS
if [ ! -f libcpt.a ]; then
    echo "Failed to build libcpt.a"
    exit 1
fi
CLIBS="-L${OBJ}/c -lcpt $CLIBS"

#V="chk scope"
V="cg chk typedefs"
for v in $V; do
    VS="$v"
    V_OBJS=
    for vs in $VS; do
	f=pt/v/${v}/${vs}.o
	if [ -f $f ]; then
	    rm $f
	fi
	$CXX $CXXFLAGS $CINCLUDES -I${SRC}/c/pt/v  -c ${SRC}/c/pt/v/${v}/${vs}.cpp -o ${f}
	if [ ! -f $f ]; then
	    echo "Failed to build $f"
	    exit 1
	fi
	V_OBJS="$f $V_OBJS"
    done 
    
    if [ -f libcv${v}.a ]; then
	rm libcv${v}.a
    fi
    $AR cr libcv${v}.a $V_OBJS
    if [ ! -f libcv${v}.a ]; then
	echo "Failed to build libcv${v}.a"
	exit 1
    fi
    CLIBS="$CLIBS -lcv${v}"
done
CLIBS="$CLIBS -lcpt"

cd ..

C="driver oparser cc1"
for c in $C; do
    if [ -f ${c}.o ]; then
	rm ${c}.o
    fi
    
    $CXX $CXXFLAGS $CINCLUDES -c ${SRC}/c/${c}.cpp -o ${c}.o
    if [ ! -f ${c}.o ]; then
	echo "Failed to build ${c}.o"
	exit 1
    fi
    C_OBJS="${c}.o $C_OBJS"
done

C="m"
for c in $C; do
    if [ -f ${c}.o ]; then
	rm ${c}.o
    fi
    
    $CXX $CXXFLAGS $CINCLUDES -c ${SRC}/con/${c}.cpp -o ${c}.o
    if [ ! -f ${c}.o ]; then
	echo "Failed to build ${c}.o"
	exit 1
    fi
    C_OBJS="${c}.o $C_OBJS"
done

if [ -f cc1 ]; then
    rm cc1
fi
$CXX ${C_OBJS} ${OBJS} ${CLIBS} -o cc1
if [ ! -f cc1 ]; then
    exit
fi


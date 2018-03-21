#!/bin/sh

set -x

AR=ar
LD=ld.lld
LORDER=lorder
CC="ccache clang"
CXX="ccache clang++"
#CXX="clang++"
AFL_CC="afl-clang"
AFL_CXX="afl-clang++"

CXX_STD=c++17
LLVM_INCLUDEDIR=`llvm-config --includedir`
LLVM_LIBDIR=`llvm-config --libdir`
LLVM_LIBS=`llvm-config --libs`
LLVM_SYSTEM_LIBS=`llvm-config --system-libs`

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
C_INCLUDES="-I${LLVM_INCLUDEDIR} -I${SRC}/c -I${SRC}/c/pt -I${SRC}/l -I${SRC}/c/l -I${OBJ}/c -I${SRC}/pt -I${SRC}/at"
FIG_INCLUDES="-I${SRC}/fig -I${SRC}/fig/pt -I${SRC}/l -I${SRC}/fig/l -I${OBJ}/fig -I${SRC}/pt -I${SRC}/at"
CLIBS="-L${LLVM_LIBDIR} $LLVM_LIBS $LLVM_SYSTEM_LIBS"

mkdir -p ${OBJ}/at
mkdir -p ${OBJ}/ada
mkdir -p ${OBJ}/c/pt/v/pa
mkdir -p ${OBJ}/c/pt/v/scope
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
    $CXX $CXXFLAGS $C_INCLUDES -c ${SRC}/at/${at}.cpp -o ${f}
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

FIG_OBJS=

$LYPP -I $SRC/fig/y $LYPP_FLAGS $SRC/fig/y/fig.parser.yy > parser.yy
$YACC $YACC_FLAGS -d -v parser.yy

if [ ! -f parser.tab.cc ]; then
    exit 1
fi
if [ -f parser.o ]; then
    rm parser.o
fi
$CXX $CXXFLAGS $FIG_INCLUDES -c parser.tab.cc -o parser.o
if [ ! -f parser.o ]; then
    echo "Problem building parser"
    exit 1
fi
FIG_OBJS="$FIG_OBJS parser.o"

$LYPP -I $SRC/fig/l -I $SRC/c/l $LYPP_FLAGS $SRC/fig/l/fig.lexer.l > fig.lexer.l
$LEX --outfile=fig.lexer.yy.cc fig.lexer.l
if [ ! -f fig.lexer.yy.cc ]; then
    exit 1
fi
if [ -f fig.lexer.o ]; then
    rm fig.lexer.o
fi

$CXX $CXXFLAGS $FIG_INCLUDES -c fig.lexer.yy.cc -o fig.lexer.o
if [ ! -f fig.lexer.o ]; then
    exit 1
fi

FIG_OBJS="$FIG_OBJS fig.lexer.o"

if [ -f pt.o ]; then
    rm pt.o
fi

if [ -f fig_driver.o ]; then
    rm fig_driver.o
fi
$CXX $CXXFLAGS $FIG_INCLUDES -c $SRC/fig/fig_driver.cpp -o fig_driver.o
if [ ! -f fig_driver.o ]; then
    echo "Problem building fig_driver"
    exit 1
fi
FIG_OBJS="$FIG_OBJS fig_driver.o"

$CXX $CXXFLAGS $FIG_INCLUDES -c ${SRC}/fig/pt/pt.cpp -o pt.o
if [ ! -f pt.o ]; then
    echo "Failed to build pt.o"
    exit 1
fi
FIG_OBJS="$FIG_OBJS pt.o"

C="m driver"
for c in $C; do
    if [ -f ${c}.o ]; then
	rm ${c}.o
    fi
    
    $CXX $CXXFLAGS $FIG_INCLUDES -I. -c ${SRC}/con/${c}.cpp -o ${c}.o
    if [ ! -f ${c}.o ]; then
	echo "Failed to build ${c}.o"
	exit 1
    fi
    FIG_OBJS="$FIG_OBJS ${c}.o"
done

PT="n"
for pt in $PT; do
    f=pt/${pt}.o
    if [ -f $f ]; then
	rm $f
    fi
    $CXX $CXXFLAGS $FIG_INCLUDES -c ${SRC}/pt/${pt}.cpp -o ${f}
    if [ ! -f $f ]; then
	echo "Failed to build $f"
	exit 1
    fi
    FIG_OBJS="$FIG_OBJS $f"
done 


if [ -f libfigpt.a ]; then
    rm libfigpt.a
fi
FIG_OJBS=`$LORDER $FIG_OBJS | tsort`
$AR cr libfigpt.a $FIG_OBJS
# $LD -r -o libfigpt.a $PT_OBJS
if [ ! -f libfigpt.a ]; then
    echo "Failed to build libcpt.a"
    exit 1
fi
# CLIBS="-L${OBJ}/fig -lfigpt $CLIBS"

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
$CXX $CXXFLAGS $C_INCLUDES -c parser.tab.cc -o parser.o
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

# $CXX $CXXFLAGS $C_INCLUDES -E c.lexer.yy.cc > c.lexer.ii
$CXX $CXXFLAGS $C_INCLUDES -c c.lexer.yy.cc -o c.lexer.o
if [ ! -f c.lexer.o ]; then
    exit 1
fi

C_OBJS="c/c.lexer.o $C_OBJS"

PT="pt n"
PT_OBJS=
for pt in $PT; do
    f=pt/${pt}.o
    if [ -f $f ]; then
	rm $f
    fi
    $CXX $CXXFLAGS $C_INCLUDES -c ${SRC}/c/pt/${pt}.cpp -o ${f}
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
#$LD -r -o libcpt.a $PT_OBJS
if [ ! -f libcpt.a ]; then
    echo "Failed to build libcpt.a"
    exit 1
fi
CLIBS="-L${OBJ}/c -lcpt $CLIBS"

#V="chk scope"
V_OBJS=
V="cg chk typedefs ping"
for v in $V; do
    VS="$v"
    for vs in $VS; do
	f=pt/v/${vs}.o
	if [ -f $f ]; then
	    rm $f
	fi
	$CXX $CXXFLAGS $C_INCLUDES -I${SRC}/c/pt/v  -E ${SRC}/c/pt/v/${vs}.cpp -o ${f}.ii
	$CXX $CXXFLAGS $C_INCLUDES -I${SRC}/c/pt/v  -c ${SRC}/c/pt/v/${vs}.cpp -o ${f}
	if [ ! -f $f ]; then
	    echo "Failed to build $f"
	    exit 1
	fi
	V_OBJS="$f $V_OBJS"
    done 
    
done
if [ -f libcv.a ]; then
    rm libcv.a
fi
$AR cr libcv.a $V_OBJS
if [ ! -f libcv.a ]; then
    echo "Failed to build libcv${v}.a"
    exit 1
fi
CLIBS="$CLIBS -lcv"
CLIBS="$CLIBS -lcpt"

cd ..

C="c_driver oparser cc1"
for c in $C; do
    if [ -f ${c}.o ]; then
	rm ${c}.o
    fi
    
    $CXX $CXXFLAGS $C_INCLUDES -c ${SRC}/c/${c}.cpp -o ${c}.o
    if [ ! -f ${c}.o ]; then
	echo "Failed to build ${c}.o"
	exit 1
    fi
    C_OBJS="${c}.o $C_OBJS"
done

C="m driver"
for c in $C; do
    if [ -f ${c}.o ]; then
	rm ${c}.o
    fi
    
    $CXX $CXXFLAGS $C_INCLUDES -c ${SRC}/con/${c}.cpp -o ${c}.o
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


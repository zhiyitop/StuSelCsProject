cc=gcc
INCLUDE_DIR=../include
LIB=libModuleMysql.a

ModuleMysql.o:ModuleMysql.c
	${cc} -c ModuleMysql.c -o ModuleMysql.o -I ${INCLUDE_DIR}

all:${LIB}
${LIB}:ModuleMysql.o
	ar -rcs ${LIB} ModuleMysql.o;cp ${LIB} ../release

.PHONY: clean
clean:

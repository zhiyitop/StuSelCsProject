cc=gcc
INCLUDE_DIR=../include
LIB=libModuleStu.a

ModuleStu.o:ModuleStu.c
	${cc} -c ModuleStu.c -o ModuleStu.o -I ${INCLUDE_DIR} -L /usr/lib/x86_64-linux-gnu/ -lmysqlclient

all:${LIB}
${LIB}:ModuleStu.o
	ar -rcs ${LIB} ModuleStu.o;cp ${LIB} ../release

.PHONY: clean
clean:
	rm *.o *.a

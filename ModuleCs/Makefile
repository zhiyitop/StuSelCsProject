cc=gcc
INCLUDE_DIR=../include
LIB=libModuleCs.a

ModuleCs.o:ModuleCs.c
	${cc} -c ModuleCs.c -o ModuleCs.o -I ${INCLUDE_DIR} -L /usr/lib/x86_64-linux-gnu/ -lmysqlclient

all:${LIB}
${LIB}:ModuleCs.o
	ar -rcs ${LIB} ModuleCs.o;cp ${LIB} ../release

.PHONY: clean
clean:
	rm *.o *.a

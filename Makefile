Main:Main.c
	gcc Main.c -o Main -I include -L release -lModuleStu -lModuleCs -lModuleMysql -L /usr/lib/x86_64-linux-gnu/ -lmysqlclient
.PHONY:clean
clean:
	rm Main

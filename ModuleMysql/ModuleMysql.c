#include<stdio.h>
#include<ModuleAll_Pub.h>
#include<mysql/mysql.h>
void self_init(){
	conn = mysql_init(NULL);
}

void self_connect(){
	if(!mysql_real_connect(conn,server,user,password,database,3306,NULL,0)){
		printf("连接失败：%s",mysql_error(conn));
	}else{
		printf("连接成功");
	}
}

void self_close(){
	mysql_close(conn);
}

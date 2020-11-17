#ifndef _STU_H_
#define _STU_H_

#include<mysql/mysql.h>
#include<string.h>
#include<stdlib.h>

MYSQL *conn;//mysql连接句柄
MYSQL_RES *res;
MYSQL_ROW *row;

//mysql连接的配置
extern char *server;
extern char *user;
extern char *password;
extern char *database;

//mysql连接语句的起始部分
extern char select_head[50];
extern char desc_head[50];
extern char insert_head[200];
extern char drop_msg_head[50];
extern char change_base_head[50];

//数据的初始化和结束
void self_init();
void self_connect();
void self_close();

/*typedef struct Student{
	int Stu_id;
	char *Stu_name;
}StudentNode;

typedef struct Cs{
	int Cs_id;
	char *Cs_name;
	char *Cs_pro;
	int Cs_hour;
	int Cs_score;
	int Cs_stuNum;
	int Cs_maxNum;
}CsNode;*/

//课程模块主控循环
void CsCtl();

//新增课程
void addCs();

//删除课程
void delCs();

//查看课程信息
void showCs();

//修改课程信息
void modifyCs();




//学生模块主控循环
void StuCtl();

//新增学生信息
void addStu();

//修改学生信息
void modifyStu();

//删除学生信息
void delStu();

//查看学生信息
void showStu();



#endif

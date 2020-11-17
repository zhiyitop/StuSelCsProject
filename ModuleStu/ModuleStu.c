#include<stdio.h>
#include<ModuleAll_Pub.h>
#include<mysql/mysql.h>
#include<time.h>

//mysql连接的配置
char *server = "localhost";
char *user = "root";
char *password = "123456";
char *database = "StuSelCsProject";

//mysql连接语句的起始部分
char select_head[50] = "select * from ";
char desc_head[50] = "desc ";
char insert_head[200] = "insert into ";
char drop_msg_head[50] = "delete from ";
char change_base_head[50] = "update ";


//主控循环
void StuCtl(){
	
	int flag=1;//是否推出标志
	char Sel_Num;//功能序号

	while(flag){
		printf("-------------------\n");
		printf("欢迎使用学生信息模块\n");
		printf("1、新增学生信息\n");
		printf("2、修改学生信息\n");
		printf("3、删除学生信息\n");
		printf("4、按学号、姓名查看学生信息\n");
		printf("5、退出课程模块\n");
		printf("------------------\n");
		printf("请选择功能序号：");
		scanf("%c",&Sel_Num);
		getchar();

		self_init();
		self_connect();

		switch(Sel_Num){
			case '1':
				addStu();
				break;
			case '2':
				modifyStu();
				break;
			case '3':
				delStu();
				break;
			case '4':
				showStu();
				break;
			case '5':
				flag=0;
				break;
			default:
				printf("输入错误请重新输入\n");
				break;
		}	

		self_close();
	}
}

void addStu(){
	
	int t;
	char insert_query[200];
	char query[500];
	char table_name[50]="Stu(Stu_id,Stu_name) value(";
	char end[5]=")";
	char temp[5]=",";
	//char field[100];
	
	char id[10];
	char name[10];

	printf("---------------------\n");
	printf("请输入学生id(用""包裹)\n");
	scanf("%s",&id);
	getchar();
	printf("请输入学生姓名(用""包裹)\n");
	scanf("%s",&name);
	getchar();
	
	strcpy(query,insert_head);
	strcat(query,table_name);
	strcat(query,id);
	strcat(query,temp);
	strcat(query,name);
	strcat(query,end);
	
	printf("%s\n",query);

	mysql_query(conn, "set names utf8");

	t = mysql_real_query(conn,query,strlen(query));
	if(t){
		printf("failed to query:%s\n",mysql_error(conn));
		return;
	}
	printf("query success!\n");
	return;
}

void modifyStu(){
	
	int t;
	char m_sel;
	char query[50];
	char table_name[50]="Stu set ";
	char query_end[50]=" where Stu_name=";
	char name1[10];
	
	strcpy(query,change_base_head);
	strcat(query,table_name);

	printf("------------------------\n");
	printf("请输入你想修改的学生姓名\n");
	scanf("%s",&name1);
	getchar();

	printf("请输入想修改的字段序号\n");
	printf("1、学生id\n");
	printf("2、学生姓名\n");
	scanf("%c",&m_sel);
	getchar();

	switch(m_sel){
		case '1':
			printf("请输入学生id\n");
			char id[10];
			char id_head[50]="Stu_id=";
			scanf("%s",&id);
			getchar();
			strcat(query,id_head);
			strcat(query,id);
			break;
		case '2':
			printf("请输入学生姓名\n");
			char name[10];
			char name_head[50]="Stu_name=";
			scanf("%s",&name);
			getchar();
			strcat(query,name_head);
			strcat(query,name);
			break;
	}

	strcat(query,query_end);
	strcat(query,name1);
	
	printf("%s\n",query);

	mysql_query(conn, "set names utf8");

	t = mysql_real_query(conn,query,strlen(query));
	if(t){
		printf("failed to query:%s\n",mysql_error(conn));
		return;
	}
	printf("query success!\n");
	
	FILE *fp1;
    time_t timep;
	struct tm *q;
	time(&timep);
	q=gmtime(&timep);
	fp1=fopen("/home/yifeng/git_respostory/StuSelCsProject/log.log","a");
	fprintf(fp1,"%d年%d月%d日 %d:%d:%dstu表中修改了一个学生信息。\n",1900+q->tm_year,1+q->tm_mon,q->tm_mday,8+q->tm_hour,q->tm_min,q->tm_sec);
	fclose(fp1); 

	return;
}

void delStu(){
	
	int t;
	char table_name[50]="Stu where Stu_name=";
	char query[500];
	char name[10];

	printf("----------------------------\n");
	printf("请输入要删除的学生姓名\n");
	scanf("%s",&name);
	getchar();

	strcpy(query,drop_msg_head);
	strcat(query,table_name);
	strcat(query,name);
	
	printf("%s\n",query);

	mysql_query(conn, "set names utf8");

	t = mysql_real_query(conn,query,strlen(query));
	if(t){
		printf("failed to query:%s\n",mysql_error(conn));
		return;
	}
	printf("query success!\n");
	return;
}

void showStu(){

	int t;
	char table_name[50]="Stu ";
	char query[50];
	char select_name[50]="where Stu_name=";
	char name[20];
	
	printf("------------------------\n");
	printf("请输入查询的学生名称\n");
	scanf("%s",&name);
	getchar();

	strcpy(query,select_head);
	strcat(query,table_name);
	strcat(query,select_name);
	strcat(query,name);
	
	printf("%s\n",query);

	t = mysql_real_query(conn,query,strlen(query));
	if(t){
		printf("failed to query:%s\n",mysql_error(conn));
		return;
	}
	printf("query success!\n");
	
	printf("Stu_id\tStu_name\n");

	res = mysql_store_result(conn);
	while(row = mysql_fetch_row(res)){
		for(t = 0;t<mysql_num_fields(res);t++){
			printf("%s\t",row[t]);
		}
		printf("\n");
	}

	return;
}

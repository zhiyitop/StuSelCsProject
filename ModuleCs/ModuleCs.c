#include<stdio.h>
#include<ModuleAll_Pub.h>
#include<mysql/mysql.h>
#include<time.h>
//mysql连接的配置
//char *server = "localhost";
//char *user = "root";
//char *password = "123456";
//char *database = "StuSelCsProject";

//mysql连接语句的起始部分
//char select_head[50] = "select * from ";
//char desc_head[50] = "desc ";
//char insert_head[200] = "insert into ";
//char drop_msg_head[50] = "delete from ";
//char change_base_head[50] = "update ";



//主控循环
void CsCtl(){

	int flag=1;//是否推出标志
	
	char Sel_Num;//功能序号
	
	while(flag){

		printf("-------------------\n");
		printf("欢迎使用课程管理模块\n");
		printf("1、新增课程\n");
		printf("2、删除课程\n");
		printf("3、查看课程信息\n");
		printf("4、修改课程信息\n");
		printf("5、退出课程模块\n");
		printf("------------------\n");
		printf("请选择功能序号：");
		scanf("%c",&Sel_Num);
		getchar();

		self_init();
		self_connect();

		switch(Sel_Num){
			case '1':
				addCs();
				break;
			case '2':
				delCs();
				break;
			case '3':
				showCs();
				break;
			case '4':
				modifyCs();
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


//新增课程
void addCs(){
	
	int t;
	char query[200];
	char table_name[50]="Cs(Cs_id,Cs_name,Cs_pro,Cs_hour,Cs_score) value(";
	char end[5]=")";
	char temp[5]=",";
	//char field[100];
	
	char id[10];
	char name[10];
	char pro[20];
	char hour[10];
	char score[10];
	
	printf("------------------------\n");
	printf("请输入课程id\n");
	scanf("%s",&id);
	getchar();
	printf("请输入课程名称\n");
	scanf("%s",&name);
	getchar();
	printf("请输入课程性质\n");
	scanf("%s",&pro);
	getchar();
	printf("请输入课程学时\n");
	scanf("%s",&hour);
	getchar();
	printf("请输入课程学分\n");
	scanf("%s",&score);
	getchar();

	strcpy(query,insert_head);
	strcat(query,table_name);
	strcat(query,id);
	strcat(query,temp);
	strcat(query,name);
	strcat(query,temp);
	strcat(query,pro);
	strcat(query,temp);
	strcat(query,hour);
	strcat(query,temp);
	strcat(query,score);
	strcat(query,end);
	
	printf("%s\n",query);
	
	mysql_query(conn, "set names 'utf8'");

	t = mysql_real_query(conn,query,strlen(query));
	if(t){
		printf("failed to query:%s\n",mysql_error(conn));
		return;
	}
	printf("query success!\n");
	return;
}

//删除课程
void delCs(){
	
	
	int t;
	char table_name[50]="Cs where Cs_name=";
	char query[200];
	char name[10];

	printf("----------------------------\n");
	printf("请输入要删除的课程名称\n");
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

//查看课程信息
void showCs(){

	int t;
	char table_name[50]="Cs ";
	char query[50];
	char select_name[50]="where Cs_name=";
	char name[20];
	
	printf("------------------------\n");
	printf("请输入查询的课程名称\n");
	scanf("%s",&name);
	getchar();

	strcpy(query,select_head);
	strcat(query,table_name);
	strcat(query,select_name);
	strcat(query,name);
	
	printf("%s",query);
	
	mysql_query(conn, "set names utf8");

	t = mysql_real_query(conn,query,strlen(query));
	if(t){
		printf("failed to query:%s\n",mysql_error(conn));
		return;
	}
	printf("query success!\n");
	
	printf("Cs_id\tCs_name\tCs_pro\tCs_hour\tCs_score\tCs_stuNum\tCs_maxNum\n");

	res = mysql_store_result(conn);
	while(row = mysql_fetch_row(res)){
		for(t = 0;t<mysql_num_fields(res);t++){
			printf("%s\t",row[t]);
		}
		printf("\n");
	}

	return;
	
}

//修改课程信息
void modifyCs(){
	
	int t;
	char m_sel;
	char query[50];
	char table_name[50]="Cs set ";
	char query_end[50]=" where Cs_name=";
	char name1[10];

	strcpy(query,change_base_head);
	strcat(query,table_name);

	printf("------------------------\n");
	printf("请输入你想修改的课程名称\n");
	scanf("%s",&name1);
	getchar();

	printf("请输入想修改的字段序号\n");
	printf("1、课程id\n");
	printf("2、课程名称\n");
	printf("3、课程性质\n");
	printf("4、课程学时\n");
	printf("5、课程学分\n");
	printf("6、课程已选人数\n");
	printf("7、课程最大可选人数\n");
	scanf("%c",&m_sel);
	getchar();

	switch(m_sel){
		case '1':
			printf("请输入课程id\n");
			char id[10];
			char id_head[50]="Cs_id=";
			scanf("%s",&id);
			getchar();
			strcat(query,id_head);
			strcat(query,id);
			break;
		case '2':
			printf("请输入课程名称\n");
			char name[10];
			char name_head[50]="Cs_name=";
			scanf("%s",&name);
			getchar();
			strcat(query,name_head);
			strcat(query,name);
			break;
		case '3':
			printf("请输入课程性质\n");
			char pro[10];
			char pro_head[50]="Cs_pro=";
			scanf("%s",&pro);
			getchar();
			strcat(query,pro_head);
			strcat(query,pro);
			break;
		case '4':
			printf("请输入课程学时\n");
			char hour[10];
			char hour_head[50]="Cs_hour=";
			scanf("%s",&hour);
			getchar();
			strcat(query,hour_head);
			strcat(query,hour);
			break;
		case '5':
			printf("请输入课程学分\n");
			char score[10];
			char score_head[50]="Cs_score=";
			scanf("%s",&score);
			getchar();
			strcat(query,score_head);
			strcat(query,score);
			break;
		case '6':
			printf("请输入课程以选人数\n");
			char stuNum[10];
			char stuNum_head[50]="Cs_stuNum=";
			scanf("%s",&stuNum);
			getchar();
			strcat(query,stuNum_head);
			strcat(query,stuNum);
			break;
		case '7':
			printf("请输入课程最大可选人数\n");
			char maxNum[10];
			char maxNum_head[50]="Cs_maxNum=";
			scanf("%s",&maxNum);
			getchar();
			strcat(query,maxNum_head);
			strcat(query,maxNum);
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
	fprintf(fp1,"%d年%d月%d日 %d:%d:%dCs表中修改了一门课程信息。\n",1900+q->tm_year,1+q->tm_mon,q->tm_mday,8+q->tm_hour,q->tm_min,q->tm_sec);
	fclose(fp1); 

	return;
}

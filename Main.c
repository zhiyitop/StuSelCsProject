#include<stdio.h>
#include<ModuleAll_Pub.h>

int main(){

	char Sel1;//功能序号

	while(1){
		printf("----------------------------\n");
		printf("欢迎使用学生选课系统\n");
		printf("A:课程模块\n");
		printf("B:学生模块\n");
		printf("----------------------------\n");
		printf("请选择模块功能序号:");
		scanf("%c",&Sel1);
		getchar();
		switch(Sel1){
			case 'A':
				printf("ModuleA\n");
				CsCtl();
				break;
			case 'B':
				printf("ModuleB\n");
				StuCtl();
				break;
			default:
				printf("输入错误请重新输入\n");
				break;
		}
	}
	return 0;
}

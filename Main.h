struct Stu{
	char Stu_Id[10];
	char Stu_Name[4];
	CsNode Stu_List[100];
	int Stu_AllCsScore;
}StuNode;
struct Cs{
	int Cs_Id;
	char Cs_Name[4];
	char Cs_Pro[10];
	int Cs_Hour;
	int Cs_Score;
	int Cs_SelNum;
}CsNode;

 
   /*此处的宏定义常量表示线性表可能达到的最大长度*/
struct student
{
	int Sid;//选手编号 
	char Sname[10];//选手姓名
	char Ssex[10];//选手性别
	char pro[10];//选手类别
	int Class;//选手班级
	int Stel;//选手电话 
    double score[10];
	int sum;
};
struct referee
{
	char Rname[10];//裁判姓名 
	char Rsex[10];//裁判性别 
	int Ttel;
	
};
typedef struct student ElemType;
typedef struct referee TempType;
#define	MAXSIZE  100
typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
}SeqList;
typedef  struct
{ 
	TempType  temp[MAXSIZE];  /*线性表占用的数组空间*/
	int       endl;    /*记录线性表中最后一个元素在数组temp[ ]中的位置（下标值），空表置为-1*/
}Seqlist;

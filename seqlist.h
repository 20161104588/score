 
   /*�˴��ĺ궨�峣����ʾ���Ա���ܴﵽ����󳤶�*/
struct student
{
	int Sid;//ѡ�ֱ�� 
	char Sname[10];//ѡ������
	char Ssex[10];//ѡ���Ա�
	char pro[10];//ѡ�����
	int Class;//ѡ�ְ༶
	int Stel;//ѡ�ֵ绰 
    double score[10];
	int sum;
};
struct referee
{
	char Rname[10];//�������� 
	char Rsex[10];//�����Ա� 
	int Ttel;
	
};
typedef struct student ElemType;
typedef struct referee TempType;
#define	MAXSIZE  100
typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	int       last;    /*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
}SeqList;
typedef  struct
{ 
	TempType  temp[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	int       endl;    /*��¼���Ա������һ��Ԫ��������temp[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
}Seqlist;

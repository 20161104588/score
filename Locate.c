#include "common.h"
#include "seqlist.h"
void input(SeqList *L)//输入 
{ 
    int r,i;
	printf("请输入学生个数:");
	scanf("%d",&r);
	L->last = r-1;
	printf("请输入学生各项信息:\n");
	for(i=0; i<=L->last; i++)
	{
		printf("请输入第%d号学生的编号:",i+1); 
		scanf("%d",&L->elem[i].Sid);
		printf("请输入第%d号学生的姓名:",i+1); 
		scanf("%s",L->elem[i].Sname);
		printf("请输入第%d号学生的性别:",i+1);
		scanf("%s",L->elem[i].Ssex);
		printf("请输入第%d号学生的班级:",i+1);
		scanf("%d",&L->elem[i].Class);
		printf("请输入第%d号学生的节目类别:",i+1);
		scanf("%s",L->elem[i].pro);
		printf("请输入第%d号学生的电话:",i+1);
		scanf("%d",&L->elem[i].Stel);
		
	}
     
}
void inputr(Seqlist *l)//输入 
{ 
    int r,i;
	printf("请输入裁判个数:");
	scanf("%d",&r);
	l->endl = r-1;
	printf("请输入裁判各项信息:\n");
	for(i=0; i<=l->endl; i++)
	{
		printf("请输入第%d号裁判的名字:",i+1);
		scanf("%s",l->temp[i].Rname);
		printf("请输入第%d号裁判的性别:",i+1);
		scanf("%s",l->temp[i].Rsex);
		printf("请输入第%d号裁判的电话:",i+1);
		scanf("%d",&l->temp[i].Ttel);
	}

}
/*int  Locate(SeqList L, int n)//查找   
{	

	int i=0;        i为扫描计数器，初值为0，即从第一个元素开始比较
	while ((i<=L.last)&&(L.elem[i].id!=n))		顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到
		i++; 
	if  (i<=L.last)
	{
		printf("该学生信息的成绩为:\n",i+1);
		printf("英语成绩=%d ",L.elem[i].Escore);
		printf("计算机成绩=%d ",L.elem[i].Cscore);
		printf("数学成绩=%d\n",L.elem[i].Mscore);
		return (i); /*若找到值为e的元素，则返回其序号
		
	} 
	else
	{
		printf("在学生信息中没有该学生!\n");  /*若没找到，则返回空序号
	}

}
void Find(SeqList* L)
{
	int q;
	printf("请输入要查找的学号:\n");
	scanf("%d",&q);
	Locate(*L,q);
}
int Insert(SeqList* L)//插入 
{
	ElemType X;
	int i,j;
	printf("请输入要添加的位置:\n");
	     scanf("%d",&i);
	printf("输入新的学生信息\n"); 
	    scanf("%d",&X.id);
		scanf("%s",X.name);
		scanf("%d",&X.Escore);
		scanf("%d",&X.Cscore);
		scanf("%d",&X.Mscore);
	if(L->last==MAXSIZE-1)
	{
		printf("表满");
		return FALSE; 
	}
	if(i<1||i>L->last+2)
	{
		printf("位序不合法"); 
	    return FALSE; 
	}
	for(j=L->last;j>=i-1;j--)
	{
		L->elem[j+1]=L->elem[j];
	}
		L->elem[i-1]=X;
		L->last++;
		return TRUE;
	
	
}
int Delete(SeqList* L)//删除  
{
	int i,q;
	printf("输入删除信息:\n");
	scanf("%d",&q);
    i=Locate(*L,q);
	int j;
	if(i<0||i>L->last+2)
	{
		printf("位序%d不存在元素\n",i);
		return FALSE;
		}
	else
	for(j=i;j<=L->last;j++)
	  L->elem[j-1]=L->elem[j];
	L->last--;
	return TRUE;
}
void onput(SeqList* L)//输出 
{
	int i;
	 for(i=0;i<=L->last;i++)
    {

		printf("%d ",L->elem[i].id);
		printf("%s ",L->elem[i].name);
		printf("英语成绩=%d ",L->elem[i].Escore);
		printf("计算机成绩=%d ",L->elem[i].Cscore);
		printf("数学成绩=%d ",L->elem[i].Mscore);
		printf("总成绩=%d\n",L->elem[i].sum);
    }
}

void sort(SeqList *L)  /*排序  根据学号排序  
{
	if(L->last<0)
	{
		printf("数组数据为空，无数据可以排序"); 
	}
	else
	{
		int i,j,n;
		struct student temp;  /*定义中间值  方便数据换位 
		n=L->last;
		for(i=0;i<n;i++)     冒泡排序 
		{
			for(j=0;j<n;j++)
		    {
		  		if(L->elem[j].sum>L->elem[j+1].sum)
		  		{
			  		temp=L->elem[j];
			  		L->elem[j]=L->elem[j+1];
			  		L->elem[j+1]=temp;
		  		}
		    }
		}
		printf("排序成功\n");
	}
	
}

void change(SeqList* L)//修改
{
    int i,q;
	printf("输入更改学生学号:\n");
	scanf("%d",&q);
    i=Locate(*L,q);
	int j;
	if(i<0||i>L->last+1)
	{
		printf("位序不存在元素\n");
	}
	else
	{
		printf("输入需要更改的信息\n"); 
	    printf("姓名："); 
		scanf("%s",L->elem[i].name);
		printf("英语成绩："); 
		scanf("%d",&L->elem[i].Escore);
		printf("数学成绩："); 
		scanf("%d",&L->elem[i].Cscore);
		printf("体育成绩："); 
		scanf("%d",&L->elem[i].Mscore);
	    printf("学生信息已更改\n");
	}
	
 } 
 void read(SeqList *L)  /*文件读取
{
	
	FILE *fp;
	int i,j;
	struct student temp[50];
	
	fp=fopen("student.txt","r");   /*定义指针 打开文 
	if(fp==NULL)
	{
		printf("open file error.\n");
		exit(-1);
	}
	else 
	{
		printf("学生信息为:\n");
		i=0;
		while(fscanf(fp,"%d %s %d %d %d\n",&temp[i].id,temp[i].name,&temp[i].Escore,&temp[i].Mscore,&temp[i].Cscore)!=EOF)	
		{			
			printf("%d ",temp[i].id);
		    printf("%s ",temp[i].name);
		    printf("%d ",temp[i].Escore);
		    printf("%d ",temp[i].Cscore);
		    printf("%d\n",temp[i].Mscore);
			i++;
		}
		for(j=0;j<=i;j++)
			L->elem[j]=temp[j];
		L->last=i-1;
		
	}
	
	fclose(fp);
} 
void save(SeqList *L)   /*保存文件 
{
	FILE *fp;
	FILE *temp;
	int i,j;
	temp=fopen("student.txt","w+");    /*定义指针 打开文件   		
	if(fp==NULL)
	{
		printf("open file error.\n");
		exit(-1);
	}
	else//把数组中的数据逐个写入student.txt。 
	{
		for(j=0;j<=L->last;j++)
		{
			fprintf(temp,"%d ",L->elem[j].id);
		    fprintf(temp,"%s ",L->elem[j].name);
		    fprintf(temp,"%d ",L->elem[j].Escore);
		    fprintf(temp,"%d ",L->elem[j].Cscore);
		    fprintf(temp,"%d\n",L->elem[j].Mscore);	
		}
		
	}
	fclose(temp);   /*关闭文件 
	exit(-1);
}*/
void menu()//菜单 
{
	SeqList L;
	int t=0;
	while(1)
	{
		printf("\t****************************************************\n");
		printf("\t*                学生信息管理系统                  *\n");
		printf("\t*               1.存入学生信息                     *\n");
		printf("\t*               2.存入裁判信息                     *\n");
		printf("\t*               3.插入学生信息                     *\n");
		printf("\t*               4.删除学生信息                     *\n");
		printf("\t*               5.显示所有学生信息                 *\n");
		printf("\t*               6.更改学生信息                     *\n");
		printf("\t*               7.成绩排序                         *\n");
		printf("\t*               8.读取文件                         *\n");
		printf("\t*               9.退出系统                         *\n");
		printf("\t****************************************************\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :  input(&L);break;//输入
			case 2 :  inputr(&L);break;//查询 
			/*case 3 :  Insert(&L);break;//插入 
			case 4 :  Delete(&L);break;//删除 
			case 5 :  onput(&L);break;//输出 
			case 6 :  change(&L);break;//更改
			case 7 :  sort(&L);break;//排序 
			case 8 :  read(&L);break;//读取文件
			case 9 :  save(&L);break;//退出系统 */
		}
	}
}
int main()
{
    menu();
	return 0;
}

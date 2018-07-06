#include "common.h"
#include "seqlist.h"
void input(SeqList *L)//输入 
{
	int r, i;
	printf("请输入选手个数:");
	scanf("%d", &r);
	L->last = r - 1;
	printf("请输入选手各项信息:\n");
	for (i = 0; i <= L->last; i++)
	{
		printf("请输入第%d号学生的编号:", i + 1);
		scanf("%d", &L->elem[i].Sid);
		printf("请输入第%d号学生的姓名:", i + 1);
		scanf("%s", L->elem[i].Sname);
		printf("请输入第%d号学生的性别:", i + 1);
		scanf("%s", L->elem[i].Ssex);
		printf("请输入第%d号学生的班级:", i + 1);
		scanf("%d", &L->elem[i].Class);
		printf("请输入第%d号学生的节目类别:", i + 1);
		scanf("%s", L->elem[i].pro);
		printf("请输入第%d号学生的电话:", i + 1);
		scanf("%d", &L->elem[i].Stel);

	}

}
void inputr(Seqlist *l)//输入 
{
	int i;

	printf("请输入裁判各项信息:\n");
	for (i = 0; i <= 4; i++)
	{
		printf("请输入第%d号裁判的名字:", i + 1);
		scanf("%s", l->temp[i].Rname);
		printf("请输入第%d号裁判的性别:", i + 1);
		scanf("%s", l->temp[i].Rsex);
		printf("请输入第%d号裁判的电话:", i + 1);
		scanf("%d", &l->temp[i].Ttel);
	}

}
void scort(SeqList *L)
{
	int i;
	int j;
	int flag = 1;
	while (flag)
	{
		printf("要打分选手编号");
		int n;
		scanf("%d",&n);
		for (i = 0; i<L->elem[i].Sid; )
		{
			if (L->elem[i].Sid != n)
			{
				i++;
			}
			else {
				break;
			}
		}
		//cout<<i<<endl;
		if (i >= L->elem[i].Sid || n <= 0)
		{
			printf("该学生编号不存在，请重新输入");
		}
		else
		{
			printf("请输入第一个评委打分:");
			scanf("%d",&L->elem[i].score[0]);
			printf("请输入第二个评委打分:");
			scanf("%d", &L->elem[i].score[1]);
			printf("请输入第三个评委打分:");
			scanf("%d", &L->elem[i].score[2]);
			printf("请输入第四个评委打分:");
			scanf("%d", &L->elem[i].score[3]);
			printf("请输入第五个评委打分:");
			scanf("%d", &L->elem[i].score[4]);

			L->elem[i].min = L->elem[i].score[0];
			for (j = 0; j<5; j++)
			{
				if (L->elem[i].score[j]<L->elem[i].min)
				{
					L->elem[i].min = L->elem[i].score[j];
				}
			}

			L->elem[i].max = L->elem[i].score[0];
			for (j = 0; j<5; j++)
			{
				if (L->elem[i].score[j]>L->elem[i].max)
				{
					L->elem[i].max = L->elem[i].score[j];
				}
			}
			L->elem[i].avg= (L->elem[i].score[0] + L->elem[i].score[1] + L->elem[i].score[2] + L->elem[i].score[3] + L->elem[i].score[4] - L->elem[i].min - L->elem[i].max) / 3;
			printf("%d号选手去掉一个最高分:%d,去掉一个最低分:%d,最后得分为:%d\n", i + 1, L->elem[i].max, L->elem[i].min, L->elem[i].avg);
			flag = 0;
		}
	}
}
/*int  Locate(SeqList L, int n)//查找   
{

	int i = 0;        //i为扫描计数器，初值为0，即从第一个元素开始比较
		while ((i <= L.last) && (L.elem[i].id != n))		//顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到
			i++;
	if (i <= L.last)
	{
		printf("该选手为:\n", i + 1);
		printf("%d ", L.elem[i].Escore);
		printf("计算机成绩=%d ", L.elem[i].Cscore);
		printf("数学成绩=%d\n", L.elem[i].Mscore);
		return (i); //若找到值为e的元素，则返回其序号

	}
	else
	{
		printf("在学生信息中没有该学生!\n");  //若没找到，则返回空序号
	}

}
void Find(SeqList* L)
{
	int q;
	printf("请输入要查找的学号:\n");
	scanf("%d", &q);
	Locate(*L, q);
}
/*int Insert(SeqList* L)//插入
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
*/void onput(SeqList* L)//输出选手
{
int i;
for(i=0;i<=L->last;i++)
{

printf("编号=%d\n",L->elem[i].Sid);
printf("姓名=%s\n",L->elem[i].Sname);
printf("性别=%s\n",L->elem[i].Ssex);
printf("班级=%d\n",L->elem[i].Class);
printf("比赛类别=%s\n",L->elem[i].pro);
printf("电话=%d\n", L->elem[i].Stel);
printf("平均分=%d\n", L->elem[i].avg);
}
}

void sort(SeqList *L)  //排序  根据学号排序
{
if(L->last<0)
{
printf("数组数据为空，无数据可以排序");
}
else
{
int i,j,n;
struct student temp;  //定义中间值  方便数据换位
n=L->last;
for(i=0;i<n;i++)     //冒泡排序
{
for(j=0;j<n;j++)
{
if(L->elem[j].avg<L->elem[j+1].avg)
{
temp=L->elem[j];
L->elem[j]=L->elem[j+1];
L->elem[j+1]=temp;
}
}
}
for (i = 0; i <= L->last; i++)
{
	printf("第%d名选手信息为\n",i + 1);
	printf("编号=%d\n", L->elem[i].Sid);
	printf("姓名=%s\n", L->elem[i].Sname);
	printf("性别=%s\n", L->elem[i].Ssex);
	printf("班级=%d\n", L->elem[i].Class);
	printf("比赛类别=%s\n", L->elem[i].pro);
	printf("电话=%d\n", L->elem[i].Stel);
	printf("平均分=%d\n", L->elem[i].avg);
}
}

}

/*void change(SeqList* L)//修改
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
}*/
void save(SeqList *L,Seqlist *l)   //保存文件
{
FILE *fp;

int j;
fp=fopen("score.csv","w");    //定义指针 打开文件
if(fp==NULL)
{
printf("open file error.\n");
exit(-1);
}
else//把数组中的数据逐个写入score.csv
{
  for(j=0;j<=L->last;j++)
  {
     fprintf(fp,"%d ",L->elem[j].Sid);
     fprintf(fp,"%s ",L->elem[j].Sname);
     fprintf(fp,"%s ",L->elem[j].Ssex);
     fprintf(fp,"%d ",L->elem[j].Class);
     fprintf(fp,"%s",L->elem[j].pro);
     fprintf(fp, "%d", L->elem[j].Stel);
     fprintf(fp, "%d", L->elem[j].score[0]);
     fprintf(fp, "%d", L->elem[j].score[1]);
     fprintf(fp, "%d", L->elem[j].score[2]);
     fprintf(fp, "%d", L->elem[j].score[3]);
     fprintf(fp, "%d", L->elem[j].score[4]);
     fprintf(fp, "%d", L->elem[j].max);
     fprintf(fp, "%d", L->elem[j].min);
     fprintf(fp, "%d", L->elem[j].avg);
  }
}
fclose(fp);   //关闭文件
exit(-1);
}
void menu()//菜单 
{
	SeqList L;
	Seqlist l;
	int t = 0;
	while (1)
	{
		printf("\t****************************************************\n");
		printf("\t*                   打分系统                       *\n");
		printf("\t*               1.存入选手信息                     *\n");
		printf("\t*               2.存入裁判信息                     *\n");
		printf("\t*               3.输入选手成绩                     *\n");
		printf("\t*               4.输出选手信息                     *\n");
		printf("\t*               5.学生名次                         *\n");
		printf("\t*               6.更改学生信息                     *\n");
		printf("\t*               7.成绩排序                         *\n");
		printf("\t*               8.读取文件                         *\n");
		printf("\t*               9.退出系统                         *\n");
		printf("\t****************************************************\n");
		scanf("%d", &t);
		switch (t)
		{
		case 1:  input(&L); break;//输入
		case 2:  inputr(&l); break;//查询 
	    case 3 :  scort(&L);break;//插入
		case 4 :  onput(&L);break;//输出
		case 5 :  sort(&L);break;//排序
		case 9 :  save(&L,&l); break;//退出系统 
		/*case 8 :  read(&L);break;//读取文件
	    case 9 :  save(&L);break;//退出系统 */
		}
	}
}
int main()
{
	menu();
	return 0;
}

#include "common.h"
#include "seqlist.h"
void input(SeqList *L)//���� 
{
	int r, i;
	printf("������ѡ�ָ���:");
	scanf("%d", &r);
	L->last = r - 1;
	printf("������ѡ�ָ�����Ϣ:\n");
	for (i = 0; i <= L->last; i++)
	{
		printf("�������%d��ѧ���ı��:", i + 1);
		scanf("%d", &L->elem[i].Sid);
		printf("�������%d��ѧ��������:", i + 1);
		scanf("%s", L->elem[i].Sname);
		printf("�������%d��ѧ�����Ա�:", i + 1);
		scanf("%s", L->elem[i].Ssex);
		printf("�������%d��ѧ���İ༶:", i + 1);
		scanf("%d", &L->elem[i].Class);
		printf("�������%d��ѧ���Ľ�Ŀ���:", i + 1);
		scanf("%s", L->elem[i].pro);
		printf("�������%d��ѧ���ĵ绰:", i + 1);
		scanf("%d", &L->elem[i].Stel);

	}

}
void inputr(Seqlist *l)//���� 
{
	int i;

	printf("��������и�����Ϣ:\n");
	for (i = 0; i <= 4; i++)
	{
		printf("�������%d�Ų��е�����:", i + 1);
		scanf("%s", l->temp[i].Rname);
		printf("�������%d�Ų��е��Ա�:", i + 1);
		scanf("%s", l->temp[i].Rsex);
		printf("�������%d�Ų��еĵ绰:", i + 1);
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
		printf("Ҫ���ѡ�ֱ��");
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
			printf("��ѧ����Ų����ڣ�����������");
		}
		else
		{
			printf("�������һ����ί���:");
			scanf("%d",&L->elem[i].score[0]);
			printf("������ڶ�����ί���:");
			scanf("%d", &L->elem[i].score[1]);
			printf("�������������ί���:");
			scanf("%d", &L->elem[i].score[2]);
			printf("��������ĸ���ί���:");
			scanf("%d", &L->elem[i].score[3]);
			printf("������������ί���:");
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
			printf("%d��ѡ��ȥ��һ����߷�:%d,ȥ��һ����ͷ�:%d,���÷�Ϊ:%d\n", i + 1, L->elem[i].max, L->elem[i].min, L->elem[i].avg);
			flag = 0;
		}
	}
}
/*int  Locate(SeqList L, int n)//����   
{

	int i = 0;        //iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�
		while ((i <= L.last) && (L.elem[i].id != n))		//˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�
			i++;
	if (i <= L.last)
	{
		printf("��ѡ��Ϊ:\n", i + 1);
		printf("%d ", L.elem[i].Escore);
		printf("������ɼ�=%d ", L.elem[i].Cscore);
		printf("��ѧ�ɼ�=%d\n", L.elem[i].Mscore);
		return (i); //���ҵ�ֵΪe��Ԫ�أ��򷵻������

	}
	else
	{
		printf("��ѧ����Ϣ��û�и�ѧ��!\n");  //��û�ҵ����򷵻ؿ����
	}

}
void Find(SeqList* L)
{
	int q;
	printf("������Ҫ���ҵ�ѧ��:\n");
	scanf("%d", &q);
	Locate(*L, q);
}
/*int Insert(SeqList* L)//����
{
ElemType X;
int i,j;
printf("������Ҫ��ӵ�λ��:\n");
scanf("%d",&i);
printf("�����µ�ѧ����Ϣ\n");
scanf("%d",&X.id);
scanf("%s",X.name);
scanf("%d",&X.Escore);
scanf("%d",&X.Cscore);
scanf("%d",&X.Mscore);
if(L->last==MAXSIZE-1)
{
printf("����");
return FALSE;
}
if(i<1||i>L->last+2)
{
printf("λ�򲻺Ϸ�");
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
int Delete(SeqList* L)//ɾ��
{
int i,q;
printf("����ɾ����Ϣ:\n");
scanf("%d",&q);
i=Locate(*L,q);
int j;
if(i<0||i>L->last+2)
{
printf("λ��%d������Ԫ��\n",i);
return FALSE;
}
else
for(j=i;j<=L->last;j++)
L->elem[j-1]=L->elem[j];
L->last--;
return TRUE;
}
*/void onput(SeqList* L)//���ѡ��
{
int i;
for(i=0;i<=L->last;i++)
{

printf("���=%d\n",L->elem[i].Sid);
printf("����=%s\n",L->elem[i].Sname);
printf("�Ա�=%s\n",L->elem[i].Ssex);
printf("�༶=%d\n",L->elem[i].Class);
printf("�������=%s\n",L->elem[i].pro);
printf("�绰=%d\n", L->elem[i].Stel);
printf("ƽ����=%d\n", L->elem[i].avg);
}
}

void sort(SeqList *L)  //����  ����ѧ������
{
if(L->last<0)
{
printf("��������Ϊ�գ������ݿ�������");
}
else
{
int i,j,n;
struct student temp;  //�����м�ֵ  �������ݻ�λ
n=L->last;
for(i=0;i<n;i++)     //ð������
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
	printf("��%d��ѡ����ϢΪ\n",i + 1);
	printf("���=%d\n", L->elem[i].Sid);
	printf("����=%s\n", L->elem[i].Sname);
	printf("�Ա�=%s\n", L->elem[i].Ssex);
	printf("�༶=%d\n", L->elem[i].Class);
	printf("�������=%s\n", L->elem[i].pro);
	printf("�绰=%d\n", L->elem[i].Stel);
	printf("ƽ����=%d\n", L->elem[i].avg);
}
}

}

/*void change(SeqList* L)//�޸�
{
int i,q;
printf("�������ѧ��ѧ��:\n");
scanf("%d",&q);
i=Locate(*L,q);
int j;
if(i<0||i>L->last+1)
{
printf("λ�򲻴���Ԫ��\n");
}
else
{
printf("������Ҫ���ĵ���Ϣ\n");
printf("������");
scanf("%s",L->elem[i].name);
printf("Ӣ��ɼ���");
scanf("%d",&L->elem[i].Escore);
printf("��ѧ�ɼ���");
scanf("%d",&L->elem[i].Cscore);
printf("�����ɼ���");
scanf("%d",&L->elem[i].Mscore);
printf("ѧ����Ϣ�Ѹ���\n");
}

}
void read(SeqList *L)  /*�ļ���ȡ
{

FILE *fp;
int i,j;
struct student temp[50];

fp=fopen("student.txt","r");   /*����ָ�� ����
if(fp==NULL)
{
printf("open file error.\n");
exit(-1);
}
else
{
printf("ѧ����ϢΪ:\n");
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
void save(SeqList *L,Seqlist *l)   //�����ļ�
{
FILE *fp;

int j;
fp=fopen("score.csv","w");    //����ָ�� ���ļ�
if(fp==NULL)
{
printf("open file error.\n");
exit(-1);
}
else//�������е��������д��score.csv
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
fclose(fp);   //�ر��ļ�
exit(-1);
}
void menu()//�˵� 
{
	SeqList L;
	Seqlist l;
	int t = 0;
	while (1)
	{
		printf("\t****************************************************\n");
		printf("\t*                   ���ϵͳ                       *\n");
		printf("\t*               1.����ѡ����Ϣ                     *\n");
		printf("\t*               2.���������Ϣ                     *\n");
		printf("\t*               3.����ѡ�ֳɼ�                     *\n");
		printf("\t*               4.���ѡ����Ϣ                     *\n");
		printf("\t*               5.ѧ������                         *\n");
		printf("\t*               6.����ѧ����Ϣ                     *\n");
		printf("\t*               7.�ɼ�����                         *\n");
		printf("\t*               8.��ȡ�ļ�                         *\n");
		printf("\t*               9.�˳�ϵͳ                         *\n");
		printf("\t****************************************************\n");
		scanf("%d", &t);
		switch (t)
		{
		case 1:  input(&L); break;//����
		case 2:  inputr(&l); break;//��ѯ 
	    case 3 :  scort(&L);break;//����
		case 4 :  onput(&L);break;//���
		case 5 :  sort(&L);break;//����
		case 9 :  save(&L,&l); break;//�˳�ϵͳ 
		/*case 8 :  read(&L);break;//��ȡ�ļ�
	    case 9 :  save(&L);break;//�˳�ϵͳ */
		}
	}
}
int main()
{
	menu();
	return 0;
}

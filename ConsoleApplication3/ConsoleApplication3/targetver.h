#pragma once

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。

// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。

struct student
{
	int Sid;//选手编号 
	char Sname[10];//选手姓名
	char Ssex[10];//选手性别
	char pro[10];//选手类别
	int Class;//选手班级
	int Stel;//选手电话 
	int score[10];
	int sum;
	int min;
	int max;
	int avg;
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
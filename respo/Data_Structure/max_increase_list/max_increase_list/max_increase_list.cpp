// max_increase_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

#define data_length 10
#define MAX 100
int F[MAX];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
//int main()
//{
//	int V[14] = { 13,7,9,16,38,24,37,18,44,19,21,22,63,15 };
//	int i, j;
//	F[13] = -1;
//	for (i = 0; i <14;i++)
//	{
//		F[i] = -1;
//		for (j = 0; j<i; j++)
//		{
//
//			if (V[i] > V[j])
//			{
//				F[i] = max(F[i], F[j] + 1);
//			}
//		}
//
//	}
//	for (i = 0; i < 14; i++)
//	{
//		printf("%d ", F[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}



//求最长的递增子序列
void max_increase_list(int d[],int max,int index)
{
	if (index==1)
	{
		return;
	}

	if (d[index-1]<d[index])
	{

	}
	else
	{

	}
}


// 求递减最长子序列
void max_desc_list()
{

}

int _data[10] = { 2,18,7,14,10,12,23,41,16,24 };

//int main()
//{
//	//int data[10] = { 2,18,7,14,10,12,23,41,16,24 };
//	max_increase_list(_data, 1);
//	system("pause");
//    return 0;
//}


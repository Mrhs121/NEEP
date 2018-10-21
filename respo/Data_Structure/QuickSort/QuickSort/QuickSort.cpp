// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

#define count 10;
#define lastindex 9;


/*
* 快速排序算法
* 
*/

//int a[10] = {12,123,543,5,1231,1,4312,3124,143,521};
int a[10] = { 6 ,1 , 2 ,7,  9 ,999, 4 , 5 ,10 , 8 };

//升序
void quickSortByAscending(int left,int right) {
	int tmp, i, j , t;
	tmp = a[left];
	i = left;
	j = right;
	if (left > right)
	{
		return;
	}
	while (i!=j)
	{
		// 从 right 向 左边边找 比基准数小的
		while (a[j]>= tmp && i<j)
		{
			j--;
		}

		// 
		while (a[i] <= tmp && i<j)
		{
			i++;
		}
		// 当走到 4 6 的时候 

		//交换两个数在数组中的位置 
		//交换两个数在数组中的位置 
		
		if (i<j)
		{
			printf("交换 %d-%d,%d-%d\n", i, a[i], j, a[j]);
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}

	

		// 从 left 向 right 找 比基准数大的
	}
	cout << "i = " << i << endl;
	a[left] = a[i];
	a[i] = tmp;

	for (int k = 0; k < 10; k++)
	{
		cout << a[k] << " ";
	}
	cout <<"\n-------- 一趟结束 -------------"<< endl;
	// 将基准数与第i个位置交换 这样就形成了 左边比基准数小右边比他大的序列
	// 然后再将左边的子串 和 右边的子串进行再次排序


	quickSortByAscending(left, i - 1);//继续处理左边的，这里是一个递归的过程 
	quickSortByAscending(i + 1, right);//继续处理右边的 ，这里是一个递归的过程 

}

// 降序
void quickSortByDescending(int left, int right) {
	int tmp, i, j, t;
	tmp = a[left]; // 选择左边第一个数为基准数
	i = left;
	j = right;
	if (left > right)
	{
		return;
	}
	while (i != j)
	{
		// 从 right 向 左边边找 比基准数小的
		// 
		while (a[j] <= tmp && i<j)
		{
			j--;
		}

		while (a[i] >= tmp && i<j)
		{
			i++;
		}

		//交换两个数在数组中的位置 
		printf("交换 %d-%d,%d-%d\n", i,a[i],j, a[j]);
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}


		a[left] = a[i];
		a[i] = tmp;
		// 从 left 向 right 找 比基准数大的
		for (int k = 0; k < 10; k++)
		{
			cout << a[k] << " ";
		}
		cout << endl;
	}



	cout << "--------- 一趟结束 ------------" << endl;
	quickSortByDescending(left, i - 1);//继续处理左边的，这里是一个递归的过程 
	quickSortByDescending(i + 1, right);//继续处理右边的 ，这里是一个递归的过程 

}

int main()
{
	
	cout << "\n-------origin data---------\n";
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl<<endl;
	//quickSortByAscending(0, 9);
	quickSortByAscending(0, 9);
	cout << "\n-------result---------\n";
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
    return 0;
}


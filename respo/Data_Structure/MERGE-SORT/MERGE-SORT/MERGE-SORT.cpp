// MERGE-SORT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
/*
* 说明： 归并排序算法 
* 思想： 分而治之，先将大串拆分成子串，然后在合并成大串
*
*/

int a[10] = { 123,1,1212,1124,41,523,114,545,156,321 };

// 归并排序
// 参数说明：
// arr[] 需要排序的数据
// left  数组的左边界
// right 数组的右边界
// tmp[] 临时数组，避免递归中反复的开辟新空间
// 递归出口: left == right

void  merge(int arr[], int left, int mid, int right, int temp[]);

void merge_sort(int arr[],int left,int right,int tmp[], char * flag)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid, tmp,"left");//左边归并排序，使得左子序列有序
		merge_sort(arr, mid + 1, right, tmp,"right");//右边归并排序，使得右子序列有序
		cout  << "\n\nmerge start   from " << flag << " left :" << left << " mid:" << mid << " right:" << right << endl;
		merge(arr, left, mid, right, tmp);//将两个有序子数组合并操作
	}
}

void merge(int arr[], int left, int mid, int right, int temp[]) {
	cout << "merge before :" << endl;
	cout << "a: ";
	for (int m = 0;m < 10;m++) {
		cout << a[m] << " ";
	}
	cout << "\ntemp: ";
	for (int m = 0;m < 10;m++) {
		cout << temp[m] << " ";
	}
	cout << endl;

	int i = left;//左序列指针
	int j = mid + 1;//右序列指针
	int t = 0;//临时数组指针
	while (i <= mid && j <= right) {

		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		}
		else {
			temp[t++] = arr[j++];
		}
	}
	while (i <= mid) {//将左边剩余元素填充进temp中
		temp[t++] = arr[i++];
	}

	while (j <= right) {//将右序列剩余元素填充进temp中
		temp[t++] = arr[j++];
	}

	t = 0;
	//将temp中的元素全部拷贝到原数组中
	while (left <= right) {
		arr[left++] = temp[t++];
	}
	cout << "merge after :" << endl;
	cout << "a  ";
	for (int m = 0;m < 10;m++) {
		cout << a[m] << " ";
	}
	cout << "\ntemp: ";
	for (int m = 0;m < 10;m++) {
		cout << temp[m] << " ";
	}
}

int main()
{

	cout << "old arr :" << endl;
	for (int i = 0;i < 10;i++) {
		cout << a[i] << " ";
	}
	int tmp[10];
	merge_sort(a, 0, 9, tmp, "all");
	cout << endl;
	cout << "new arr :" << endl;
	for (int i = 0;i < 10;i++) {
		cout << a[i] << " ";
	}
	system("pause");
    return 0;
}


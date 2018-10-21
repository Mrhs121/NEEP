// MERGE-SORT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
/*
* ˵���� �鲢�����㷨 
* ˼�룺 �ֶ���֮���Ƚ��󴮲�ֳ��Ӵ���Ȼ���ںϲ��ɴ�
*
*/

int a[10] = { 123,1,1212,1124,41,523,114,545,156,321 };

// �鲢����
// ����˵����
// arr[] ��Ҫ���������
// left  �������߽�
// right ������ұ߽�
// tmp[] ��ʱ���飬����ݹ��з����Ŀ����¿ռ�
// �ݹ����: left == right

void  merge(int arr[], int left, int mid, int right, int temp[]);

void merge_sort(int arr[],int left,int right,int tmp[], char * flag)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid, tmp,"left");//��߹鲢����ʹ��������������
		merge_sort(arr, mid + 1, right, tmp,"right");//�ұ߹鲢����ʹ��������������
		cout  << "\n\nmerge start   from " << flag << " left :" << left << " mid:" << mid << " right:" << right << endl;
		merge(arr, left, mid, right, tmp);//����������������ϲ�����
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

	int i = left;//������ָ��
	int j = mid + 1;//������ָ��
	int t = 0;//��ʱ����ָ��
	while (i <= mid && j <= right) {

		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		}
		else {
			temp[t++] = arr[j++];
		}
	}
	while (i <= mid) {//�����ʣ��Ԫ������temp��
		temp[t++] = arr[i++];
	}

	while (j <= right) {//��������ʣ��Ԫ������temp��
		temp[t++] = arr[j++];
	}

	t = 0;
	//��temp�е�Ԫ��ȫ��������ԭ������
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


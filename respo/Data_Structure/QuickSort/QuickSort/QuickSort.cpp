// QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

#define count 10;
#define lastindex 9;


/*
* ���������㷨
* 
*/

//int a[10] = {12,123,543,5,1231,1,4312,3124,143,521};
int a[10] = { 6 ,1 , 2 ,7,  9 ,999, 4 , 5 ,10 , 8 };

//����
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
		// �� right �� ��߱��� �Ȼ�׼��С��
		while (a[j]>= tmp && i<j)
		{
			j--;
		}

		// 
		while (a[i] <= tmp && i<j)
		{
			i++;
		}
		// ���ߵ� 4 6 ��ʱ�� 

		//�����������������е�λ�� 
		//�����������������е�λ�� 
		
		if (i<j)
		{
			printf("���� %d-%d,%d-%d\n", i, a[i], j, a[j]);
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}

	

		// �� left �� right �� �Ȼ�׼�����
	}
	cout << "i = " << i << endl;
	a[left] = a[i];
	a[i] = tmp;

	for (int k = 0; k < 10; k++)
	{
		cout << a[k] << " ";
	}
	cout <<"\n-------- һ�˽��� -------------"<< endl;
	// ����׼�����i��λ�ý��� �������γ��� ��߱Ȼ�׼��С�ұ߱����������
	// Ȼ���ٽ���ߵ��Ӵ� �� �ұߵ��Ӵ������ٴ�����


	quickSortByAscending(left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ��� 
	quickSortByAscending(i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ��� 

}

// ����
void quickSortByDescending(int left, int right) {
	int tmp, i, j, t;
	tmp = a[left]; // ѡ����ߵ�һ����Ϊ��׼��
	i = left;
	j = right;
	if (left > right)
	{
		return;
	}
	while (i != j)
	{
		// �� right �� ��߱��� �Ȼ�׼��С��
		// 
		while (a[j] <= tmp && i<j)
		{
			j--;
		}

		while (a[i] >= tmp && i<j)
		{
			i++;
		}

		//�����������������е�λ�� 
		printf("���� %d-%d,%d-%d\n", i,a[i],j, a[j]);
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}


		a[left] = a[i];
		a[i] = tmp;
		// �� left �� right �� �Ȼ�׼�����
		for (int k = 0; k < 10; k++)
		{
			cout << a[k] << " ";
		}
		cout << endl;
	}



	cout << "--------- һ�˽��� ------------" << endl;
	quickSortByDescending(left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ��� 
	quickSortByDescending(i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ��� 

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


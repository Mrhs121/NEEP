#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
#define maxn 100
int main()
{
	//�������ݣ�b[i]��¼�±�i��n�Ĳ��½������еĳ��ȣ�c[i]��¼�±�i�������еĺ�������±�
	int a[maxn], b[maxn], c[maxn];
	int n, i, j, max, p;
	cout << "��������ĳ��ȣ�";
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = 1;
		c[i] = 0;
	}

	for (i = n-1; i>=1; i--)
	{
		max = 0;
		p = 0;
		for ( j = i+1; j <=n; j++)
		{
			if (a[i]<a[j] && b[j]>max)
			{
				max = b[j];
				p = j;
			}
			if (p!=0)
			{
				b[i] = b[p] + 1;
				c[i] = p;

			}
		}
	}

	max = 0;
	p = 0;
	
	for ( i = 1; i <=n; i++)
	{
		cout << "b["<<i<<"]=" << b[i] << endl;
		if (b[i] > max)
		{
			max = b[i];
			p = i;
		}
	}
	cout << "max length is:" << max << "  the first index in list is :"<<p<<endl;

	while (p!=0)
	{
		cout << a[p] << " ";
		p = c[p];
	}

	system("pause");
	return 0;
}
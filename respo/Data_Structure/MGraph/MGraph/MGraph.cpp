 // MGraph.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
* ���ݽṹ ͼ �� ��������㷨
*/
//#include "stdafx.h"
#include "Graph.h"
#include "City.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    
    cout<<"==================================================\n";
	City c0("����", 0);
	City c1("����", 1);
	City c2("�Ϻ�", 2);
	City c3("�˴�", 3);
	City c4("����", 4);
	City c5("�ϲ�", 5);
	// 0 1
	// 0 2
	// 0 4
	// 1 2
	// 2 3
	//cout << c0;
	const int vertexNum = 6;
	//int a[vertexNum] = {1,2,3,4};
	City a[vertexNum] = {c0,c1,c2,c3,c4,c5};
	// һ��6������ 6���ߵ�ͼ
	Graph<City> g(a,vertexNum,6);       
	g.printArc();
	system("pause");
	//g.DFSTraverse(0);
	int coh;
	while (1) {
		cin >> coh;
		g.BFSTraverse(coh);
		cout << endl << endl;
	}
	
//	system("pause");
    return 0;
}

//int main()
//{
//
//	cout << c.getName() << endl;
//	system("pause");
//	return 0;
//}


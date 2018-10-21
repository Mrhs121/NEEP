 // MGraph.cpp : 定义控制台应用程序的入口点。
//
/*
* 数据结构 图 的 深度优先算法
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
	City c0("北京", 0);
	City c1("广州", 1);
	City c2("上海", 2);
	City c3("宜春", 3);
	City c4("深圳", 4);
	City c5("南昌", 5);
	// 0 1
	// 0 2
	// 0 4
	// 1 2
	// 2 3
	//cout << c0;
	const int vertexNum = 6;
	//int a[vertexNum] = {1,2,3,4};
	City a[vertexNum] = {c0,c1,c2,c3,c4,c5};
	// 一个6个顶点 6条边的图
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


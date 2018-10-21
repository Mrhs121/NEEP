#pragma once

#include <iostream>
using namespace std;

const int MaxSize = 10; //最多有多少个顶点
template<class DataType>

class Graph
{
private:
	DataType vertex[MaxSize]; // 存储顶点
	int arc[MaxSize][MaxSize]; // 邻接矩阵 即边
	int vertexNum;  // 顶点个数
	int arcNum; // 边的个数
	int visited[MaxSize]; //顶点是否被访问
public:
	Graph(DataType v[], int _vertexNum, int _arcNum);
	void  reSetVisitedTable();
	void  printArc();
	//深度优先算法 v:第一个被访问的顶点
	void DFSTraverse(int v);
	// 广度优先算法
	void BFSTraverse(int v);
};

template<class DataType>

// 构造一个图
// v:顶点数组 vertexNum:顶点个数 arcNum弧的个数
Graph<DataType>::Graph(DataType v[], int _vertexNum, int _arcNum)
{
	this->vertexNum = _vertexNum;
	this->arcNum = _arcNum;
	for (int i=0;i < this->vertexNum;i++) 
	{
		this->vertex[i] = v[i];
		this->visited[i] = 0;
	}

	cout << "开始初始化邻接矩阵！" << this->vertexNum << " 个顶点  " << this->arcNum << " 条边" << endl;
	for (int j = 0;j < MaxSize;j++) 
	{
		for (int k = 0;k < MaxSize;k++) 
		{
			arc[j][k] = 0; // 0 表示 i 到 k 的两个顶点之间没有边
		}
	}
	cout << "\n邻接矩阵初始化完毕！" << endl;
	
	for (int  m = 0; m < arcNum; m++)
	{
		int v1,v2;
		cout << "input :";        
		cin >> v1 >> v2;
		arc[v1][v2] = 1; // 表示v1 和 v2 两个顶点之间存在一条边
		arc[v2][v1] = 1;
	}


}

// 还原顶点访问表
template<class DataType>
inline void Graph<DataType>::reSetVisitedTable()
{
	for (int i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}
}

template<class DataType>
inline void Graph<DataType>::printArc()
{

	cout << "打印邻接矩阵" << endl;
	// 先把各顶点的代号打印出来
	int i, j;
	for (i = 0; i < this->vertexNum; i++)
	{
		cout << "\t" << vertex[i];
	}
	cout << endl;
	for (i = 0; i < vertexNum; i++)
	{
		cout << vertex[i]<<"\t";
		for (j = 0;  j < vertexNum; j++)
		{
			cout << arc[i][j]<<"\t";
		}
		cout << endl;  
	}
	cout << endl;
	
}

// 深度优先遍历 先输出第一个顶点，visited置为1（表示已经访问过），然后下一个，为空的话出栈
template<class DataType>
inline void Graph<DataType>::DFSTraverse(int v)
{
	this->reSetVisitedTable();
	cout << vertex[v]; visited[v] = 1;
	for (int j = 0;j < vertexNum;j++)
	{
		if (arc[v][j] == 1 && visited[j] == 0)
		{
			DFSTraverse(j);
		}
	}
}

// 广度优先算法 使用队列 非递归实现
template<class DataType> 
inline void Graph<DataType>::BFSTraverse(int v)
{
	this->reSetVisitedTable();
	// 顶点队列
	int Q[MaxSize];
	int front=-1 , last = -1;
	cout<<vertex[v]; visited[v] = 1; 
	// 将顶点表中的第 v 个元素入队列
	Q[++last] = v;
	while (front!=last)
	{
		//将编号紧挨着的顶点出队，然后开始找与这个顶点的邻接顶点
		v = Q[++front];
		for (int i = 0;i < MaxSize;i++)
		{

			if (arc[v][i] == 1 && visited[i] == 0)
			{
				cout << vertex[i];
				visited[i] = 1;
				Q[++last] = i;
			}
		}
	}
}

#pragma once

#include <iostream>
using namespace std;

const int MaxSize = 10; //����ж��ٸ�����
template<class DataType>

class Graph
{
private:
	DataType vertex[MaxSize]; // �洢����
	int arc[MaxSize][MaxSize]; // �ڽӾ��� ����
	int vertexNum;  // �������
	int arcNum; // �ߵĸ���
	int visited[MaxSize]; //�����Ƿ񱻷���
public:
	Graph(DataType v[], int _vertexNum, int _arcNum);
	void  reSetVisitedTable();
	void  printArc();
	//��������㷨 v:��һ�������ʵĶ���
	void DFSTraverse(int v);
	// ��������㷨
	void BFSTraverse(int v);
};

template<class DataType>

// ����һ��ͼ
// v:�������� vertexNum:������� arcNum���ĸ���
Graph<DataType>::Graph(DataType v[], int _vertexNum, int _arcNum)
{
	this->vertexNum = _vertexNum;
	this->arcNum = _arcNum;
	for (int i=0;i < this->vertexNum;i++) 
	{
		this->vertex[i] = v[i];
		this->visited[i] = 0;
	}

	cout << "��ʼ��ʼ���ڽӾ���" << this->vertexNum << " ������  " << this->arcNum << " ����" << endl;
	for (int j = 0;j < MaxSize;j++) 
	{
		for (int k = 0;k < MaxSize;k++) 
		{
			arc[j][k] = 0; // 0 ��ʾ i �� k ����������֮��û�б�
		}
	}
	cout << "\n�ڽӾ����ʼ����ϣ�" << endl;
	
	for (int  m = 0; m < arcNum; m++)
	{
		int v1,v2;
		cout << "input :";        
		cin >> v1 >> v2;
		arc[v1][v2] = 1; // ��ʾv1 �� v2 ��������֮�����һ����
		arc[v2][v1] = 1;
	}


}

// ��ԭ������ʱ�
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

	cout << "��ӡ�ڽӾ���" << endl;
	// �ȰѸ�����Ĵ��Ŵ�ӡ����
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

// ������ȱ��� �������һ�����㣬visited��Ϊ1����ʾ�Ѿ����ʹ�����Ȼ����һ����Ϊ�յĻ���ջ
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

// ��������㷨 ʹ�ö��� �ǵݹ�ʵ��
template<class DataType> 
inline void Graph<DataType>::BFSTraverse(int v)
{
	this->reSetVisitedTable();
	// �������
	int Q[MaxSize];
	int front=-1 , last = -1;
	cout<<vertex[v]; visited[v] = 1; 
	// ��������еĵ� v ��Ԫ�������
	Q[++last] = v;
	while (front!=last)
	{
		//����Ž����ŵĶ�����ӣ�Ȼ��ʼ�������������ڽӶ���
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

// Trie.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include "KeyWordArticleMap.h"
#define MAX 26
/*
*  �ֵ��� 
*
*
*/

typedef struct  TrieNode
{
	int value;
 	bool isAWord; // ����Ƿ�����ڵ��Ǹ��Ǹ�����   
	struct TrieNode * next[MAX];    // ��һ������ ��26�ֿ��ܣ�����ֻ����Сд���ʣ�26��Ӣ�ĵ��ʣ�
									// ÿ�����ʿ���ͨ�� x - 'a' ������ƫ����
								// �Ӷ��γ�һ������16�������ֵ���
	TrieNode() {
		value = 19009;
		cout << "construction" << endl;
	}
	void getValue() {
		cout << value << endl;
	}

}Trie;


// search


// createTrie �� �����еĵ��ʹ����һ���ֵ��� 
// ����: words һ�����ʵļ���
//       root  �ֵ����ĸ��ڵ�,������ĵ�ַ���ݽ��� 
void createTrie(TrieNode ** root, char *words[])
{ 
	if (*root == NULL) {
		cout << "init root node" << endl;
		*root = new TrieNode();
	}
	
}



// insert




int main()
{
	//char a = 'g';
	//char *words[10] = {"apple","abc","ate" ,"balance" ,"aply" ,"date" ,"data" ,"database" ,"cat" ,"calculate" };
	//TrieNode * root = NULL;
	//createTrie(&root,words);
	//root->getValue();

	KeyWordArticleMap * a[100];

	//for (int i = 0;i < 100;i++) {
	//	a[i] = NULL;
	//}

	cout << sizeof(a) << endl;


	system("pause");
    return 0;
}


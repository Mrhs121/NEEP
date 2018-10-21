// Trie.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include "KeyWordArticleMap.h"
#define MAX 26
/*
*  字典树 
*
*
*/

typedef struct  TrieNode
{
	int value;
 	bool isAWord; // 标记是否这个节点是个是个单词   
	struct TrieNode * next[MAX];    // 下一个单词 有26种可能（这里只考虑小写单词，26个英文单词）
									// 每个单词可以通过 x - 'a' 来计算偏移量
								// 从而形成一颗类似16叉树的字典树
	TrieNode() {
		value = 19009;
		cout << "construction" << endl;
	}
	void getValue() {
		cout << value << endl;
	}

}Trie;


// search


// createTrie ： 用现有的单词构造出一颗字典树 
// 参数: words 一个单词的集合
//       root  字典树的根节点,将自身的地址传递进来 
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


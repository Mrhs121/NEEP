// git.cpp : 定义控制台应用程序的入口点。
//


#ifdef WINVER
#include "stdafx.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
#define YES 1 // 是堆
#define NO -1
#define maxsize 100 // 规定二叉树的节点总数不超过100
/*
* *  二叉树 前中后序遍历，非递归遍历（利用堆）（注：图的非递归遍历用的是队列）
* *  作者：黄晟
* */

typedef struct BTree {
	int data;
	struct BTree* lchild;
	struct BTree* rchild;
	int count;
}BTree;

typedef struct BTree_char {
	char data;
	struct BTree_char * lchild;
	struct BTree_char * rchild;
}BTree_char;

struct ThrNode
{
    char data;
    ThrNode * lchild,*rchild;
    int ltag,rtag;
};


int BST_Insert(BTree **T,int key);
typedef struct TStack {
	BTree * data[50];
	int top;
}TStack;

void printTstack(TStack S){
    int i = -1;
    while( (i = S.top--)!=-1 ){
        printf("%d ",S.data[i]->data);
    }
    printf("\n");
}

typedef struct Qu {
	BTree * data[100];
	// int LeverCount[50];
	int front, rear;
}Qu;



//先序自动创建二叉树
int _data_sort1[] = {10,9,5,4,3,-1,-1,-1,6,-1,7,-1,-1,-1,11,-1,12,-1,-1};
int _data_sort[] = {5,4,3,-1,-1,-1,10,6,-1,-1,11,-1,-1};
int _data_non_sort[] = {5,4,6,-1,-1,-1,10,12,-1,-1,11,-1,-1};
int _data_non_sort2[] = {5,4,3,10,12,11};
int _data1[] = {1,2,3,-1,-1,4,8,-1,-1,9,10,-1,-1,-1,5,6,-1,-1,7,-1,-1};
int _data_complete[] = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
int _data_notcomplete[] = {1,2,4,-1,-1,5,10,-1,-1,-1,3,6,-1,-1,7,-1,-1};
int _data3[] = {1,2,3,4,-1,-1,-1,5,-1,-1,6,7,-1,-1,-1};
int _data[] = {1,2,3,4,-1,-1,5,-1,-1,6,-1,-1,7,-1,-1};
int _data2[] = { 1,2,3,-1,-1,-1,5,-1,-1 };
int _data_sortTree[] = {6,2,1,-1,-1,4,3,-1,-1,-1,8,-1,-1};
//用于计算后缀表达式，存储在二叉树中
char _data_char[] = { '*','+','a','#','#','b','#','#','*','c','#','#','-','#','d','#','#' };
char _data_char2[] = { '+','+','a','#','#','b','#','#','+','c','#','#','+','d','#','#','e','#','#' };

static int _count = 0;
int _Lever = 0;


// 计算最大宽度
// 以及计算层数
// 采用层序遍历的思想
int BTWidth(BTree * t) {
	int LeverCount[100];
	int max = -1;
	Qu _queue;
	_queue.front = -1;
	_queue.rear = -1;
	int last = 0;
	int Lever = 0;
	int count = 0;
	_queue.data[++_queue.rear] = t;
	BTree * p;
	while (_queue.front < _queue.rear) {
		p = _queue.data[++_queue.front];
		count += 1;
		if (p->lchild != NULL)
			_queue.data[++_queue.rear] = p->lchild;
		if (p->rchild != NULL)
			_queue.data[++_queue.rear] = p->rchild;
		// 关键	当每一层扫描完了之后，那么下一层的所有节点也就入队了
		if (_queue.front == last) {
			Lever++;
			cout << "count:" << count << endl;
			LeverCount[Lever] = count;
			// echoLeverWidth[Lever] = count;
			last = _queue.rear;
			count = 0;
		}
	}
	max = LeverCount[1];
	//cout<<"_max:"<<max<<endl;
	for (int i = 1;i <= Lever;i++) {
		if (max<LeverCount[i])
			max = LeverCount[i];
	}
	cout << "the tree's Lever is:\nthe tree's maxWidth is:" << Lever << max << endl;
	return max;
}



bool isEmpty(TStack s) {
	if (s.top == -1) {
		//cout<<"kong\n";
		return true;
	}
	else {
		//cout<<"not empty"<<endl;
		return false;
	}
}

void push(TStack * s, BTree * node) {
	s->data[++(s->top)] = node;
}

BTree * pop(TStack * s)
{

	return s->data[s->top--];
}

BTree * getTop(TStack s)
{
	return s.data[s.top];
}


BTree_char* createTree_char(BTree_char* T) {

	cout << "输入数据(-1表示空节点):";
	char data;
	//scanf("%d",&data);
	cout << _data_char2[_count] << endl;;
	data = _data_char2[_count];
	_count++;
	if (data == '#')
		return NULL;
	else
	{
		T = (BTree_char*)malloc(sizeof(BTree_char));
		T->data = data;
		cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree_char(T->lchild);
		cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createTree_char(T->rchild);
	}
	return T;
}
int AddTreeCount(BTree * tree){
	if(tree == NULL)
		return 0;
	int l=0,r=0;
	tree->count = AddTreeCount(tree->lchild)+AddTreeCount(tree->rchild);
	return tree->count+1;
}

BTree* createTree(BTree* T,int _data[]) {

	//cout << "输入数据(-1表示空节点):";
	int data;
	//scanf("%d",&data);
	//cout << _data[_count] << endl;;
	data = _data[_count];
	_count++;
	if (data == -1)
		return NULL;
	else
	{
		T = (BTree*)malloc(sizeof(BTree));
		T->data = data;
		//cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createTree(T->lchild,_data);
		//cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createTree(T->rchild,_data);
	}
	return T;
}

ThrNode * createThrTree(ThrNode * T,int _data[]) {

	//cout << "输入数据(-1表示空节点):";
	int data;
	//scanf("%d",&data);
	//cout << _data[_count] << endl;;
	data = _data[_count];
	_count++;
	if (data == -1)
		return NULL;
	else
	{
		T = (ThrNode*)malloc(sizeof(ThrNode));
		T->data = data;
		T->ltag = 0;
		T->rtag = 0;
		//cout << "input " << data << " 的左子树:" << endl;
		T->lchild = createThrTree(T->lchild,_data);
		//cout << "input " << data << " 的右子树:" << endl;
		T->rchild = createThrTree(T->rchild,_data);
	}
	return T;
}


// 中序线索化链表，左孩子 根节点 右孩子
// ThrNode ** pre 传的是二级指针，直接对外部实体进行修改
void createThread(ThrNode * node,ThrNode ** pre)
{
    if(node == NULL){
        return ;
    }
    //printf("线索化\n");
    createThread(node->lchild,pre);
    if(node->lchild==NULL) {
        //printf("1 zhi qian");
        node->ltag = 1;
        //printf("设置%c的前驱\n",node->data);
        node->lchild = *pre; //设置前驱
    }
    
    //if(node->rchild == NULL) node->rtag = 1; // 如果孩子为空，则设置为后继
    if((*pre)!= NULL && (*pre)->rchild==NULL ) {
        //printf("设置%c的后继%c\n",(*pre)->data,node->data);
        (*pre)->rchild=node; // 设置后记
        (*pre)->rtag = 1;
    }
    (*pre)=node;
   
    createThread(node->rchild,pre);
}

ThrNode * FirstNode(ThrNode * p){
	while(p!=NULL && p->ltag==0){
		//printf("-->\n");
		p = p->lchild;
	}
	return p;
}

ThrNode * NextNode(ThrNode * p){

	if(p->rtag == 0)
		return FirstNode(p->rchild); //如果右节点是孩子节点，那么可能有很多节点在下方
	else
		return p->rchild; // 如果右节点为后继节点，那么直接返回后继节点
}
void InOrderThrTree(ThrNode * tree){
	ThrNode * p ;
	for(p = FirstNode(tree);p!=NULL;p=NextNode(p))
		printf("%d ",p->data );
	printf("\n");
}
// 839真题 答案 一颗二叉树采用标准存储
// 判断这棵树是否为堆的条件
int isSatisfyHeap(BTree * tree) {
	BTree * stack[maxsize];
	int top = -1;
	stack[++top] = tree;
	BTree * p;
	while (top != -1)
	{
		p = stack[top--];

		// 左右孩子均不能大于根结点
		if (p->lchild != NULL)
		{

			if (p->data < p->lchild->data)
			{
				return -1;
			}

			stack[++top] = p->lchild;
		}

		if (p->rchild != NULL)
		{

			if (p->data < p->rchild->data)
			{
				return -1;
			}

			stack[++top] = p->lchild;
		}
	}
	return 1;
}

void PreOrderBiTreeWithOutLeaf(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		if (T->lchild != NULL || T->rchild != NULL) {
			printf("%d ", T->data);
		}
		PreOrderBiTreeWithOutLeaf(T->lchild);
		PreOrderBiTreeWithOutLeaf(T->rchild);
	}
}

void PreOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", T->data);
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}

void PreOrderBiTreeWithLever(BTree *T,int lever)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf(" %d-----> %d ",lever ,T->data);
		PreOrderBiTreeWithLever(T->lchild,lever+1);
		PreOrderBiTreeWithLever(T->rchild,lever+1);
	}
}

void postOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
	//	printf("%d ", T->data);
		postOrderBiTree(T->lchild);
		postOrderBiTree(T->rchild);
		printf("%d ", T->data);
    }
}

void PreOrderBiTree_char(BTree_char *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		PreOrderBiTree_char(T->lchild);
		PreOrderBiTree_char(T->rchild);
	}
}

void InOrderBiTree(BTree *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//	printf("%d ", T->data);
		InOrderBiTree(T->lchild);
		cout << T->data << " ";
		InOrderBiTree(T->rchild);
	}
}

void InOrderBiTree_char(BTree_char *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		//	printf("%d ", T->data);
		InOrderBiTree_char(T->lchild);
		cout << T->data << " ";
		InOrderBiTree_char(T->rchild);
	}
}

// 非递归中序遍历
void InOrder(BTree * tree){
	TStack s;
	BTree * p = tree;
	s.top = -1;
	while(p!=NULL || !isEmpty(s)){
		//printf("--<\n");
		if(p!=NULL){
			push(&s,p);
			p = p->lchild;
		} else {
			//printf("-->\n");
			p = pop(&s);
			printf("%d ",p->data);
			p = p->rchild;
		}
	}
}


// 将中序序列转换成数学表达式
void BTree_char2Exp(BTree_char * T, int deep) {

	//    cout<<"-->\n";
	if (T == NULL)
		return;
	else if (T->lchild == NULL && T->rchild == NULL)
		printf("%c", T->data);
	else {
		if (deep>1) {
			printf("(");
		}
		BTree_char2Exp(T->lchild, deep + 1);
		printf("%c", T->data);
		BTree_char2Exp(T->rchild, deep + 1);
		if (deep>1)
			printf(")");
	}
}
void BTree_char2E(BTree_char * T) {
	BTree_char2Exp(T, 1);
}



// 二叉树的层序遍历 使用队列若该节点的左右孩子不为空，则入队
void LeverOrder(BTree * root)
{
    int front = -1;
    int rear = -1;
    BTree * Q[1000];
    int last = 0;
    Q[++rear] = root;
    last = rear;
    int l=1; // 不仅可以得到层数，还可以计算每层的节点数
    BTree * q = (BTree*)malloc(sizeof(BTree));
    while (front != rear)
    {
        q = Q[++front];
        printf("%d:%d\t",l,q->data);
        // 左右孩子入队
        if (q->lchild != NULL)
            Q[++rear] = q->lchild;
        if (q->rchild != NULL)
            Q[++rear] = q->rchild;
        if(front == last){
            last = rear;
            l++;
            printf("\n");
        }
    }

}
// 非递归前序遍历 OK
void PreOrder(BTree * T)
{
	cout << "非递归前序遍历" << endl;
	int top = -1;
	BTree * s[1000];
	while (T != NULL || top != -1)
	{
		while (T != NULL)
		{
			cout << T->data << endl;
			s[++top] = T;
			T = T->lchild;
		}
		if (top != -1)
		{
            // gettop and pop 
			T = s[top--];
			T = T->rchild;
		}
	}
}

// 判断一棵树是否平衡
void Judge_AVL(BTree * tree,int * balance,int *h){
	int bl=0,br=0,hl=0,hr=0; // 左右孩子平衡标志以及高度
	if(tree==NULL)
	{
		*h = 0;
		*balance = 1;
	}
	else if(tree->lchild==NULL && tree->rchild==NULL){
		//printf("\n 叶子结点 : %d\n",tree->data);
		*h = 1;
		*balance = 1;
	}
	else{
		Judge_AVL(tree->lchild,&bl,&hl);
		Judge_AVL(tree->rchild,&br,&hr);
		*h = (hl>hr?hl:hr)+1; // 当前节点的高度为自节点的最大高度在上自身
		if(abs(hl-hr)<2){
			//printf("\n----> ccurrent node is :%d 左高度:%d 右高度:%d\n",tree->data,hl,hr);
			*balance = bl&&br;
		} else {
			*balance = 0;
		}
	}

}
int predata = -10000;
// 判断一棵树是否是平衡树
int JudgeBST(BTree * tree){
    int b1,b2;
    if(tree == NULL)
        return 1;
    else {
		// 中序遍历的写法
		b1  = JudgeBST(tree->lchild);
		// 
		if(b1==0 || predata >= tree->data)
			return 0;
		predata = tree->data;
		printf("current node %d\n",tree->data);
		b2 = JudgeBST(tree->rchild);
		return b2;
    }
}

void testJudgeBST(){
	printf("---> test Judge BST\n");
	BTree * tree = (BTree*)malloc(sizeof(BTree));
	tree = createTree(tree,_data_sort);
	LeverOrder(tree);
	printf("is Ordered %s\n---------------------\n",JudgeBST(tree)==1?"yes":"no");

	_count = 0;
	predata = -1111;
	BTree * tree2 = (BTree*)malloc(sizeof(BTree));
	tree2 = createTree(tree2,_data_non_sort);
	LeverOrder(tree2);
	printf("is Ordered %s\n---------------------\n",JudgeBST(tree2)==1?"yes":"no");

	BTree * bst = (BTree *)malloc(sizeof(BTree));
	int i = 0;
	_count = 0;
	predata = -1111;
	for(i=0;i<(sizeof(_data_non_sort2)/sizeof(_data_non_sort[0]));i++){
		BST_Insert(&bst , _data_non_sort2[i]);
	}
	LeverOrder(bst);
	printf("is Ordered %s\n---------------------\n",JudgeBST(bst)==1?"yes":"no");
}

// 在一棵查找树中，找第k小的数，时间复杂度O(long2n);
// 思路：判断左树的节点个数与k的大小，如果左边的节点的个数+1（左子树的根节点）等于k-1，那么说明当前节点即为所求节点
//		如果k小于，那么说明在左边，接着在左边找第k小的即可
//		如果大于则说明节点在当前节点的右边，接着在右边找k_min-tree->lchild->count-2（当前节点加上当前节点的直接左孩子）小的节点
BTree * Search_K_Min(BTree * tree,int k_min){
	
	if(k_min<1 || k_min>tree->count+1){
		printf("无！\n");
		return NULL;
	}
		
	if(tree->lchild == NULL){
		if(k_min==1)
			return tree;
		else
			return Search_K_Min(tree->rchild,k_min-1);
	}
	else {
		if((k_min-1) == tree->lchild->count+1)
			return tree;
		if(tree->lchild->count+1 > k_min-1)
			return Search_K_Min(tree->lchild,k_min);
		if(tree->lchild->count+1 < k_min-1)
			return Search_K_Min(tree->rchild,k_min-tree->lchild->count-2);
	}
}
//寻找最近的公共祖先
// 从根节点开始遍历，如果node1和node2中的任一个和root匹配
// ，那么root就是最低公共祖先。 
// 如果都不匹配，则分别递归左、右子树，
// 如果有一个 节点出现在左子树，
// 并且另一个节点出现在右子树，则
// root就是最低公共祖先. 
// 如果两个节点都出现在左子树，
// 则说明最低公共祖先在左子树中，
// 否则在右子树
BTree * ancestor(BTree* root, int node1, int node2)
{
    // 有点复杂
        if (root == NULL)
            return NULL;
     
        if (node1 == root->data 
            || node2 == root->data)
            return root;
     
        BTree * cur = NULL;
     
        BTree * left_lca = ancestor(root->lchild, node1, node2);
        BTree * right_lca = ancestor(root->rchild, node1, node2);
        if (left_lca && right_lca)
            return root;
        if (left_lca == NULL)
            return right_lca;
        else
            return left_lca;
}

// 王道解法
BTree * ancestor_wd(BTree * root,BTree * p,BTree * q)
{
    return  NULL;
}

//非递归后序遍历
void postOrder(BTree * tree)
{

	int i = 0;
	TStack s;

	s.top = -1;
	BTree * p = tree;
	BTree * r = NULL;
	while (p != NULL || !isEmpty(s))
	{
		//cout<<"if "<<s.top<<"----------"<<s.data[s.top]->data<<endl;
		if (p != NULL) {
			push(&s, p);
			// 	直到左孩子为空
			p = p->lchild;
		}
		else
		{
			p = getTop(s);


			// 如果是从左边孩子返回的，那么就以为接下来要遍历root的又右孩子
			// 否则说明root的左右孩子均遍历完成，那么就直接else输出当前root节点即可
			if (p->rchild&&p->rchild != r)
			{
				p = p->rchild; //接着遍历root的右孩子
				push(&s, p);
				p = p->lchild; // 右孩子同样也是往左边开始寻找
			}
			else
			{
				// 当前节点的左右孩子均为空，则输出
				p = pop(&s);
				printf("%5d", p->data);
				r = p;//记录root的直接邻接孩子
				p = NULL;//回到上一层
			}
		}
	}
	printf("\n");
}

typedef struct
{
	BTree * bt;
	int tag;
}_stack;

_stack s[100];
// 非递归后续遍历的第二种写法
void postOrder2(BTree * tree){
	printf("post 2\n");
	int top = 0;
	BTree * bt = tree;
	while(bt!=NULL || top>0){
		while(bt!=NULL){
			s[++top].bt = bt;
			s[top].tag = 0;
			bt = bt->lchild;

		}
		while(top!=0 && s[top].tag==1){
			printf("%d ",s[top].bt->data);
			top--;
		}
		if(top!=0){
			s[top].tag = 1;
			bt = s[top].bt->rchild;
		}
	}
}

// 查找key的祖先节点
void SearchByPostOrder(BTree * tree,int key)
{

	int i = 0;
	TStack s,s2;
	
    s.top = -1;
    s2.top = -1;
	
    BTree * p = tree;
	BTree * r = NULL;
	while (p != NULL || !isEmpty(s))
	{
		//cout<<"if "<<s.top<<"----------"<<s.data[s.top]->data<<endl;
		if (p != NULL) {
			push(&s, p);
			// 	直到左孩子为空
			p = p->lchild;
		}
		else
		{
			p = getTop(s);
			if(p->data == key){
                //  此方法还可以计算连个节点最近的公共祖先
                //  copy各自的祖先，然后最后比较即可
                printf("top = %d\n",s.top);
                printTstack(s);
                exit(1);
			}
			// 如果是从左边孩子返回的，那么就以为接下来要遍历root的又右孩子
			// 否则说明root的左右孩子均遍历完成，那么就直接else输出当前root节点即可
			if (p->rchild&&p->rchild != r)
			{
				p = p->rchild; //接着遍历root的右孩子
				push(&s, p);
				p = p->lchild; // 右孩子同样也是往左边开始寻找
			}
			else
			{
				// 当前节点的左右孩子均为空，则输出
				p = pop(&s);
				//printf("%5d", p->data);
				r = p;//记录root的直接邻接孩子
				p = NULL;//回到上一层
			}
		}
	}
	printf("\n");
}

void swap(BTree * b) {
	if (b) {
		swap(b->lchild);
		swap(b->rchild);
		// 从最底端开始交换，子结点所有子结点交换了之后
		// 交换这个两个上头的子结点
		BTree * temp = b->lchild;
		b->lchild = b->rchild;
		b->rchild = temp;
	}
}
//将前序变成后序序列 表达式
void preToPost(char pre[], int l1, int h1, char post[], int l2, int h2) {

	if (l1 <= h1) {

		// 处理结点，的第一个结点即为  的最后一个结点
		post[h2] = pre[l1];
		// 处理左边的左子树
		int half = (h1 - l1) / 2;
		preToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
		preToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}
// 获取与key的数值相同的路径
void getPathByKey(BTree * T,int key){
    if(T==NULL){
        return;
    }    
   // printf("hello world");
} 

void testPath(){
    int data[] = {10,5,4,-1,-1,7,-1,-1,12,-1,-1};
    BTree * T = NULL;
    T = createTree(T,data);
    LeverOrder(T);
    cout<<"------------------"<<endl;
    cout<<" ----> "<<T->data<<endl;
    PreOrderBiTree(T);
    getPathByKey(T,22);
}


void testBtree() {
	BTree * BST_search(int ,BTree*);
    BTree *T = NULL;
	cout << "--------------- create tree-------------------\n";
	T = createTree(T,_data_sortTree);
	cout << "\n---------------   finish  ---------------------\n";
	LeverOrder(T);
    cout << "\ntest" << endl;
	PreOrderBiTreeWithLever(T,1);
    /*
    PreOrderBiTree(T);
	cout << endl << "非叶子结点：";
	PreOrderBiTreeWithOutLeaf(T);
    cout<<endl;
    InOrderBiTree(T);
    cout << endl;
    BTree * t = BST_search(10,T);
    if(t!=NULL){
        cout<<"bst search res is:"<<t->data<<endl;
    }else{
        cout<<"not find "<<1<<"in the tree "<<endl;
    }
    
    
    
    cout<<"-------------------------------\n";
    char * pre = "1245367";
	char post[100];
	preToPost(pre, 0, 6, post, 0, 6);
	cout << "pre order:" << pre << endl;
	cout << "post order :" << post << endl;
    */
}

void testBtree_char() {
	BTree_char * T = NULL;
	T = createTree_char(T);
	PreOrderBiTree_char(T);
	cout << endl;
	InOrderBiTree_char(T);
	cout << endl;
	BTree_char2E(T);
	cout << endl;
}

// 查找树的创建/插入
int BST_Insert(BTree ** T,int key){
    if(*T == NULL){
        *T = (BTree*)malloc(sizeof(BTree));
        (*T)->data = key;
        (*T)->lchild=(*T)->rchild = NULL;
        return 1;
    }
    else if(key==(*T)->data){
        return 0;
    } else if(key<(*T)->data){
        // 直接对原链进行修改
        return BST_Insert(&(*T)->lchild,key);
    } else {
        return BST_Insert(&(*T)->rchild,key);
    }
}

//   查找树的递归查找
BTree * BST_search(int data,BTree * T){
    if(T==NULL){
        return  NULL;
    }
    if(data == T->data){
        return T;
    }
    if(data < T->data){
        return BST_search(data,T->lchild);
    }else{
        return BST_search(data,T->rchild);
    }
}
// 在给定 排序树中 输出比 key 大的结点 从大到小
void OutPut(BTree * bst_tree,int key){
    if(bst_tree == NULL){
        return;
    }
    if(bst_tree->rchild != NULL){
        OutPut(bst_tree->rchild,key);
    }
    if(bst_tree->data > key){
        printf("biger :%d\n",bst_tree->data);
    } else {
        printf("small :%d\n",bst_tree->data);
    }
    if(bst_tree->lchild!=NULL){
        OutPut(bst_tree->lchild,key);
    }
}

BTree * search_small(BTree * t,int k){
    return  NULL;
}

// 测试查找树
void testBST(){
    BTree* T=NULL ;
   // int q[] = {10,4,5,2,3,6,11};
    int q[] = {5,3,10,1,4,8,13};
    T = createTree(T,_data1);
    int i=0;
    //for(i=0;i<7;i++){
      //  BST_Insert(&T,q[i]);
    //}
    //InOrderBiTree(T);
    cout<<"---------------------\n";
    //PreOrderBiTree(T);
    cout<<"---------------------\n";
    LeverOrder(T);
    cout<<"----------------------\n";
    //OutPut(T,4);
}

typedef struct 
{
	BTree * t;
	int tag;
}tagstack;

// 查找制定节点的所有祖先节点
// 采用后续非递归的思想
void search(BTree * tree,int x){
	tagstack s[100];
	int top = 0;
	int i = 0;
	while(tree!=NULL || top>0){
		while(tree!=NULL && tree==NULL?0:tree->data != x){
			printf("push : %d\n",tree->data );
			s[++top].t = tree;
			s[top].tag = 0;
			tree = tree->lchild;
		}
		if(tree->data == x){
			printf("所有的祖先节点为:\n");
			for(i=1;i<=top;i++){
				printf("%d\t",s[i].t->data);
			}
			exit(1);
		}
		while(top!=0 && s[top].tag==1){
			top--;
		}
		if(top!=0){
			s[top].tag = 1;
			tree = s[top].t->rchild;
		}
	}
}

// 判断一棵树是否是完全树
// 思想：根据层序遍历，因为层序遍历是从上到下，从左到右，如果是一颗完全二叉树（每一层的节点都是从左边开始的）的话，
// 		所有的空节点全在队列的最后面，若不是完全二叉树，那么空节点后面肯定还有非空的
int isComplete(BTree * tree){
	//int result = 0;
	Qu _queue;
	_queue.front = -1;
	_queue.rear = -1;
	_queue.data[++_queue.rear] = tree;
	BTree * node;
	while(_queue.front < _queue.rear){
		node = _queue.data[++_queue.front];
		if(node){
			_queue.data[++_queue.rear] = node->lchild;
			_queue.data[++_queue.rear] = node->rchild;
		} else {
			// 如果再度列中碰到了空的节点，那么遍历队列中剩下的数据
			// 如果剩余的数据中有非空的节点，那么就说明不是完全树
			while(_queue.front < _queue.rear){
				node = _queue.data[++_queue.front];
				if(node)
					return 0;
			}
		}
	}
	return 1;
}
void testThreadTree(){
	BTree * tree ;
	tree = createTree(tree,_data_notcomplete);
	InOrderBiTree(tree);
	printf("\n");
	_count = 0;
	ThrNode * pre = (ThrNode*)malloc(sizeof(ThrNode));
	ThrNode * thrtree;
	thrtree = createThrTree(thrtree,_data_notcomplete);
	
	createThread(thrtree,&pre);
	printf("pre->data %d\n",pre->data);
	//pre->rchild = NULL; //不能拉下这两句
	//pre->rtag = 1;

	InOrderThrTree(thrtree);
}

void testAddTreeCount(){
	BTree * tree = (BTree*)malloc(sizeof(BTree));
	tree = createTree(tree,_data_sort1);
	AddTreeCount(tree);
	int k ;
	scanf("%d",&k);
	BTree * k_min = Search_K_Min(tree,k);
	if(k_min != NULL)
		printf("k_min : %d\n",k_min->data);
	printf("%d %d %d\n",tree->count,tree->lchild->lchild->count,tree->rchild->count);
}
int main()
{
	testAddTreeCount();
	//testJudgeBST();
	// PreOrderBiTree(tree);
 //    printf("\n层序遍历\n");
 //    LeverOrder(tree);
 //    printf("后序遍历\n");
 //    postOrderBiTree(tree);
	// printf("\n非递归后序遍历\n");
	//postOrder(tree);
	// postOrder2(tree);
	// printf("\n中序遍历\n");
	// InOrderBiTree(tree);
	// printf("\n");
	// InOrder(tree);
	//printf("\niscomplete %d\n",isComplete(tree));
    //SearchByPostOrder(tree,5);

    /*
    //PreOrderBiTree(tree);
	LeverOrder(tree);
	int balance=0;
	int h=0;
	Judge_AVL(tree,&balance,&h);
	printf("%d %d\n",balance,h);
	*/
    // postOrderBiTree(tree);
	// int num;
	// scanf("%d",&num);
	// search(tree,num);
    //testPath();
//testBtree();
//
//testBST();
    //    testAncestor();
   // testBST();
//	testBtree();
	//testBtree_char();
	//int echoLeverWidth[100];
	/*
	int max = BTWidth(T);
	cout<<"max width is:"<<max<<endl;
	*/

	/*
	cout<<"\n------------------------------\n";
	//cout<<endl;
	postOrder(T);
	cout<<"\n------------------------------"<<endl;
	swap(T);
	PreOrderBiTree(T);
	postOrder(T);
	//PreOrder(T);

	*/



	/*
	LeverOrder(T);
	int res = isSatisfyHeap(T);
	cout << "res : " << res<<endl;
	if(res == YES)
	{
	cout << "此树是堆" << endl;
	}
	else
	{
	cout << "此树不是堆" << endl;
	}
	system("pause");
	*/
#ifdef WINVER
	printf("win");
	system("pause");
#endif // WINVER

	cout << endl;
	return 0;
}


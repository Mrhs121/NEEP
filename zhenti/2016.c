#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./myhead.h"
#include <string.h>
#include "../datastruct/tools/mytools.h"
//#include "../datastruct/myStrcut.h"
int _data1[] = {1,2,3,-1,-1,4,8,-1,-1,9,10,-1,-1,-1,5,6,-1,-1,7,-1,-1};

typedef struct product
{	
	char * name;
	double price;	
}Product;	

int bitsSwapRequired(int x,int y){
	int count = 0;
	int i = 0;
	for(i=0;i<32;i++){
		if( (x&(0x1<<i)) ^ (y&(0x1<<i)) ){
			count++;
		}
	}
	return count;
}

// 蔡依林解法
int htoi(char *s){
	int num = 0;
	int i = 0;
	int n = 0;
	char c;
	if(s[i]=='0'){
		i++;
		if(s[i]=='x' || s[i]=='X')
			i++;
	}
	while((c=s[i++])!='\0'){
		if(c>='0' && c<='9'){
			num = c-'0';
		} else if(c>='a' && c<='z'){
			num = c-'a'+10;
		} else if(c>='A' && c<='Z'){
			num = c-'A'+10;
		}
		n = 16*n+num;
	}
	return n;
}
//  链表的选择排序，无头节点
void ss(){
  int data[10];
    int i = 0;
    srand(time(NULL));
    for(i=0;i<10;i++){
         data[i] = rand()%(rand()%100)+1;
    }
    LNode * list = createWithoutHead(data,10);
    printList(list);
    LNode  *h=list, *p, *pre ,*max_pre ,*max ;
    list = NULL;
    while(h!=NULL){
        p=max=h;
        pre=max_pre=NULL;
        while(p!=NULL){
            // 移动p
            if(p->data>max->data){
                max = p;
                max_pre = pre;
            }
            pre = p;
            p = p->next;
        }
        // 摘链，关键：如何在没有头节点的链表中处理好pre
        if(max==h){
            h = h->next;
        } else {
            // 摘下当前最大的结点
            // h逐渐减少
            max_pre->next = max->next;
        }

        //printList(list);
        //没有haed的链表的头插法，随后的序列为剩序
        max->next = list;
        list = max;
        if(h!=NULL)
            printList(h);
        // 当 h 上的结点全部取下来之后，结束循环
    }
   printList(list);
}

void readProduct(){
	FILE * in = fopen("data.in","r");
	FILE * out = fopen("data.out","w");
	Product products[100];
	char name[20];
	double price;
	int count=0;
	char  currentProduct[20] = "";
	double sum  = 0.0;
	int isFirst = 1;
	while(fscanf(in,"%s",name)!=EOF && fscanf(in,"%lf",&price)!=EOF){
		if(isFirst==1 || strcmp(name,currentProduct)){
			if(isFirst==0){
				fprintf(out, "%s %0.2lf\n",currentProduct,sum);	
			}
			sum = 0.0;
			strcpy(currentProduct,name);
			isFirst = 0;
		}
		
		sum+=price;
	}
	fprintf(out, "%s %0.2lf\n",currentProduct,sum);	
}

// 十字链表表示稀疏矩阵
// 采用非递归前序遍历
BTree * linkLeafNode(BTree *T)
{  
    
    BTree * list = (BTree*)malloc(sizeof(BTree));
    
    BTree * p = list;
    int top = -1;
    int linking = 0;
    BTree * s[1000];
    while (T != NULL || top != -1)
    {
        while (T != NULL)
        {
            //cout << T->data << endl;
            if(T->lchild==NULL && T->rchild==NULL){
                printf("linking %d\n",T->data);
                p->lchild = T;
                p = p->lchild;
                linking = 1;
            }
            s[++top] = T;
            if(linking == 1){
                T = NULL;
                linking = 0;
            } else {
                T = T->lchild;
            }
        }
        if (top != -1)
        {
            // gettop and pop
            T = s[top--];
            T = T->rchild;
        }
    }
    return list;
}
void testlinkLeafNode(){
    BTree * tree  = (BTree*)malloc(sizeof(BTree));
    tree = createTree(tree,_data1);
    PreOrderBiTree(tree);
    printf("\n");
    BTree * head = (BTree*)malloc(sizeof(BTree));
    //head->lchild = (BTree*)malloc(sizeof(BTree))
    head =  linkLeafNode(tree);
    BTree * p = head->lchild;
    printf("after linked leaf node\n");
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->lchild;
    }
    printf("\n 注意观察经这个结果 \n");
    
    PreOrderBiTree(tree);
    printf("\n");
   
}
int test2016()
{
    printf("---> test 2016\n");
	testlinkLeafNode();
	//readProduct();
	//printf("%d\n",htoi("abc"));
	//ss();
    // int a,b;
	// printf("input a and b:");
	// scanf("%d %d",&a,&b);
	// printf("need swap %d\n",bitsSwapRequired(a,b));
	return 1;
}

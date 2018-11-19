/*************************************************************************
	> File Name: linklist.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Sep 2018 07:17:19 PM CST
 ************************************************************************/

/**
 *
 *
 * 文件说明：线性表的链式表示，即为链表
 *
 *
 *
 */
#include<stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct LNode{
    int data;
    struct LNode * next;
}LNode,*linklist;

// create linklist with headnode
LNode * create(int data[],int n)
{
    LNode * head = (linklist)malloc(sizeof(LNode)); 
    head->data = -1;
    LNode * m = head;
    int i = 0;
    for(i=0;i<n;i++){
        LNode *  node = (linklist)malloc(sizeof(LNode));
        node->data = data[i];
        node->next = NULL;
        m->next = node;
        m = node;
    }
    return head;
}



// create linklist with headnode
LNode * createWithSort(int data[],int n)
{
    LNode * head = (linklist)malloc(sizeof(LNode));
    head->data = -1;
    head->next  = NULL;
    LNode * m = head;
    LNode * insertsPre = head;
    LNode * insert = insertsPre->next;
    int i = 0;
    for(i=0;i<n;i++){
        insertsPre = head;
        insert = insertsPre->next;
        LNode *  newnode = (linklist)malloc(sizeof(LNode));
        newnode->data = data[i];
        newnode->next = NULL;
        // 处理第一个节点
        if(head->next==NULL){
            // 感觉这段有没有都没有什么关系
            m->next = newnode;
            m = newnode;
        } else {

            // 寻找插入点
            while(insert!=NULL && insert->data<data[i]){
                insertsPre = insertsPre->next;
                insert  = insertsPre->next;
            }
            // 插入
            newnode->next = insert;
            insertsPre->next = newnode;
        }
    }
    return head;
}


// create linklist with headnode
LNode * createWithoutHead(int data[],int n)
{

    LNode * head = (linklist)malloc(sizeof(LNode)); 
    head->data = data[0];
    LNode * m = head;
    int i = 0;
    for(i=1;i<n;i++){
        LNode *  node = (linklist)malloc(sizeof(LNode));
        printf("%p,%p\n",&node,node);
        node->data = data[i];
        node->next = NULL;
        m->next = node;
        m = node;
    }
    return head;
}
void print(LNode * head){
    LNode * temp;
    if(head->data != -1){
        temp = head;
    } else {
        temp = head->next;
    }
    while(temp!=NULL){
        printf("%5d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// void del(linklist &L,int a){
//     LNode * p;
//     printf("del %p,%p\n",L,&L);
    
//     if(L == NULL)
//         return;
//     if(L->data == a){
//         p = L;
//         printf("%p,%d,",&L,L->data);
//         L = L->next;
//         printf("%p\n",&L);
//         free(p);
//         del(L,a);
//        // printf("aa");
//     } else {
//         del(L->next,a);
//        // printf("bb");
//     }
    
// }

void change(LNode * head){
    head->data = 33333;
}
// void test()
// {
 
//     int a = 10;
//     int b = 20;
//     printf("----> %p,%p",&a,&b);
//     printf("-----------------------\n\n");
//     LNode * head = (linklist)malloc(sizeof(LNode));
//     int data[5] = {1,2,2,3,4};
//     head = create(data,5);
//     //print(head);
    
//     LNode * head2 = (linklist)malloc(sizeof(LNode));
//     head2 = createWithoutHead(data,5);
//     print(head2);
//     change(head2);
//     print(head2);
//     printf("\n\n----->the oringin :%p\n",&head2->next);
//     del(head2,2);
//     printf("the new data :%p\n",&head2->next);
//     printf("----------------------\n");
//     print(head2);
// //    return 0;

// }



// 2018 839 判断表b是否包含在a中 时间O(n)
int  isAIncludeB(LNode *a,LNode*b)
{
    LNode * _a = a->next;
    LNode * _b = b->next;
    // 如果匹配链 首元素的值比目标链的首元素都小
    // 那么肯定不包含
    if(_b->data < _a->data){
        return FALSE;
    }
    while(_a!=NULL){
        if(_a->data == _b->data){
            // 同时移动
            _a = _a->next;
            _b = _b->next;
        } else {
            // 不匹配的情况下 子表复原到表头
            _b = b->next;
            _a = _a->next;
        }
        // 如果走完了，那么说明吧全部匹配好了
        if(_b==NULL){
            return TRUE;
        }
    }
    if(_a==NULL && _b!=NULL){
        return FALSE;
    } else {
        return TRUE;
    }
    //return FALSE;
}


LNode * insert(LNode * head,LNode * p){
    if(head==NULL){
        return p;
    }
    printf("hello\n");
    LNode * cur = head;
    while(cur->next!=NULL && cur->next->data<p->data)
        cur = cur->next;

    p->next = cur->next;
    cur->next = p;
    return head;
}
LNode * insert2(LNode * head,LNode * p){
    if(head==NULL){
        return p;
    }
    
    LNode * pre = head;
    LNode * cur = pre->next;
    while(cur!=NULL && cur->next->data<p->data){
        pre = pre->next;
        cur = pre->next;
    }
    p = cur;
    pre->next = p;
    return head;
}
int main()
{

    int a[] = {888,2,5,214,5,41,4};
    LNode * ss = createWithSort(a,7);
    LNode * p = (LNode*)malloc(sizeof(LNode));
    int in;
    scanf("%d",&in);
    p->data = in;
    p->next = NULL;
    print(ss);
    insert(ss,p);
    print(ss);
    // LNode * datas[7];
    // int i=0;
    // for(i=0;i<7;i++){
    //     datas[i] = (LNode*)malloc(sizeof(LNode));
    //     datas[i]->data = a[i];
    //     datas[i]->next = NULL;
    // }
    // LNode * head = (LNode*)malloc(sizeof(LNode));
    // head->next = NULL;
    // for(i=0;i<7;i++){
    //     head = insert(head,datas[i]);
    // }
    //Node * ss = createWithSort(a,7);
    //print(head);
    // int a[] = {1,2,3,4,5,6,7,8};
    // int b[] = {1,2,3};
    // LNode * A = create(a,8);
    // LNode * B = create(b,3);
    // if(isAIncludeB(A,B)){
    //     printf("A include B\n");
    // } else {
    //     printf("not included B\n");
    // }
    return 0;

} 

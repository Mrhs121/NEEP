/*************************************************************************
	> File Name: 18_839.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Sat 22 Sep 2018 08:17:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define YES 1
#define NO 0
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

// 2018 839 判断表b是否包含在a中 时间O(n)
int  isAIncludeB(LNode *a,LNode*b)
{
    LNode * _a = a->next;
    LNode * _b = b->next;
    LNode * save = _a;
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
            _a = save->next;
            save  = _a;
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

// a 是否 在 b中 （不要求连续）
int isAIncludeB2(LNode * a,LNode * b){
    if(a == NULL){
        return YES;
    }
    LNode * pa = a->next;
    LNode * pb = b->next;
    while(pb!=NULL && pa->data>=pb->data){
        if(pb->data == pa->data){
             return isAIncludeB2(pa->next,pb->next);
        } else {
            pb = pb->next;
        }
    }
    printf("---->");
    return NO;
}

int main()
{
    int a[] = {2,2,3,3,5,6,7,8};
    int b[] = {2,3,5};
    LNode * A = create(a,8);
    LNode * B = create(b,3);
    if(isAIncludeB2(B,A)){
        printf("A include B\n");
    } else {
        printf("not included B\n");
    }
    return 0;
}


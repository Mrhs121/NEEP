/*************************************************************************
	> File Name: removeduplicates.c
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Sep 2018 04:36:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
// 声明一个link结构体类型
typedef struct Link{
    int data;
    struct Link *next;
}Link,*test; // 取一个别名

void print(Link * head){
    while(head->next != NULL){
        printf("%d---->",head->data);
        head = head->next;
    }
}

void loginfo(char * message)
{
    printf(message);
    printf("\n");
}

Link * Created(int data[],int size)
{
    int i = 1;
    loginfo("create Link list");
    Link * head = (test)malloc(sizeof(Link));
    head->data = data[0];
    Link * temp = head;
    for(i=1;i<size;i++){
        Link * node = (Link*)malloc(sizeof(Link)); 
        node->data = data[i]; 
        node->next = NULL;

        temp->next = node;
        temp = node;
    }
    return head;
}



// 839 15年真题 移除单链表的重复数据，不使用缓冲区
void removeduplicates(Link * head){
    Link * p = head;
    while(p->next != NULL){
        Link * move = p;
        while(move->next!=NULL){
            if(move->next->data == p->data){
                printf("remove ----> %d\n",p->data);
                move->next = move->next->next;
            }else{
                move = move->next;
            }
        }
        p = p->next;
    }
    
}

int main()
{
    int data[6] = {1,2,1,4,2,6};
    Link * head = Created(data,6);
    //printf("%d",head->data);
    print(head);
    removeduplicates(head);
    printf("\n-------after  remove---------\n-");
    print(head);
    return 0;
}

#include<stdio.h>  
#include<malloc.h> 
typedef struct{  
    float coef;  //ϵ��  
    int expn;    //ָ��  
}ElemType;  
  
typedef struct LNode{  //�������  
    ElemType data;  
    struct LNode *next;  
}*LinkList;  
  
void MakeNode(LinkList &s,ElemType e){  
    //���ɽ��  
    s=(LinkList)malloc(sizeof(LNode));  
    s->data=e;  
}  
  
void InsAfter(LinkList p,LinkList s){  
    //������  
    s->next=p->next;p->next=s;  
}  
  
int compare(ElemType e1,ElemType e2){  
    //�Ƚ�  
    if(e1.expn>e2.expn)  
        return 1;  
    else if(e1.expn<e2.expn)  
        return -1;  
    return 0;  
}  
  
void OrderInsert(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType)){  
    //�������  
    LinkList p=L,q=p->next,s;  
    while(q){  
        int n=compare(e,q->data);  
        if(n<0){    
            MakeNode(s,e);  
            InsAfter(p,s);break;  
        }  
        else if(n==0)  break;  
        p=p->next;q=p->next;  
    }  
    MakeNode(s,e);InsAfter(p,s); //��󣬷������һ��λ��  
}  
  
void InitList(LinkList &L){  
    //��ʼ��  
    L=(LinkList)malloc(sizeof(LNode));  
    L->next=NULL;  
}  
  
void SetCurElem(LinkList &p,ElemType e){ //���ý��  
    p->data.coef=e.coef;  
    p->data.expn=e.expn;  
}  
  
void CreatePolyn(LinkList &L,int m){  
    InitList(L);ElemType e;e.coef=0.0;e.expn=-1;  
    SetCurElem(L,e);//����ͷ��������Ԫ��  
    for(int i=1;i<=m;i++){  
        scanf("%f%d",&e.coef,&e.expn);  //����ֵ  
        OrderInsert(L,e,compare);  
    }  
}  
  
void show(LinkList L){  
    //�������  
    LinkList p=L->next;  
    if(p){ //��һ�����  
        printf("%f^%d",p->data.coef,p->data.expn);  
        p=p->next;  
    }  
    while(p){  
        if(p->data.coef>0)  
            printf("+");  
        printf("%f^%d",p->data.coef,p->data.expn);  
        p=p->next;  
    }  
    printf("/n");  
}  
  
void ListDestroy(LinkList &L){  
    //����  
    LinkList p=L,q;  
    while(p){  
        q=p;  
        p=p->next;  
        free(q);  
    }  
}  
  
  
void Add(LinkList &L1,LinkList &L2){  
    //����ʽ���  
    LinkList p1=L1->next,p2=L2->next,r1=L1,q;//r1ʼ��ָ�������β��,p1��p2��ʾ��ǰ���  
    while(p1&&p2){  
        int n=compare(p1->data,p2->data);  
        switch(n){  
        case -1:{r1->next=p1;r1=p1;p1=p1->next;break;} //L1�е�ֵС������֮  
        case 1:{r1->next=p2;r1=p2;p2=p2->next;break;}   //L2�е�ֵС������֮  
        case 0:{    //��ͬ  
                float sum=p1->data.coef+p2->data.coef;  
                if(sum==0){q=p1;p1=p1->next;free(q);} //ɾ��L1�е�  
                else{p1->data.coef=sum;  //����L1�е�  
                    r1->next=p1;r1=p1;p1=p1->next;}  
                q=p2;p2=p2->next;free(q);  //ͳһɾ��L2�е�  
               }  
        }  
    }  
        if(p1)  
            r1->next=p1;  //���L1  
        else  
            r1->next=p2;  //���L2  
        free(L2);L2=q=NULL;p1=p2=r1=NULL;  
}  
 
void main(){  
    LinkList L1,L2;  
    CreatePolyn(L1,4);  
    show(L1);  
    CreatePolyn(L2,3);  
    show(L2);  
    Add(L1,L2);  
    show(L1);  
}  
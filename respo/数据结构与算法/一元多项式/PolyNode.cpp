#include<stdio.h>  
#include<malloc.h> 
typedef struct{  
    float coef;  //系数  
    int expn;    //指数  
}ElemType;  
  
typedef struct LNode{  //结点类型  
    ElemType data;  
    struct LNode *next;  
}*LinkList;  
  
void MakeNode(LinkList &s,ElemType e){  
    //生成结点  
    s=(LinkList)malloc(sizeof(LNode));  
    s->data=e;  
}  
  
void InsAfter(LinkList p,LinkList s){  
    //插入结点  
    s->next=p->next;p->next=s;  
}  
  
int compare(ElemType e1,ElemType e2){  
    //比较  
    if(e1.expn>e2.expn)  
        return 1;  
    else if(e1.expn<e2.expn)  
        return -1;  
    return 0;  
}  
  
void OrderInsert(LinkList &L,ElemType e,int(*compare)(ElemType,ElemType)){  
    //有序插入  
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
    MakeNode(s,e);InsAfter(p,s); //最大，放在最后一个位置  
}  
  
void InitList(LinkList &L){  
    //初始化  
    L=(LinkList)malloc(sizeof(LNode));  
    L->next=NULL;  
}  
  
void SetCurElem(LinkList &p,ElemType e){ //设置结点  
    p->data.coef=e.coef;  
    p->data.expn=e.expn;  
}  
  
void CreatePolyn(LinkList &L,int m){  
    InitList(L);ElemType e;e.coef=0.0;e.expn=-1;  
    SetCurElem(L,e);//设置头结点的数据元素  
    for(int i=1;i<=m;i++){  
        scanf("%f%d",&e.coef,&e.expn);  //输入值  
        OrderInsert(L,e,compare);  
    }  
}  
  
void show(LinkList L){  
    //输出方法  
    LinkList p=L->next;  
    if(p){ //第一个输出  
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
    //销毁  
    LinkList p=L,q;  
    while(p){  
        q=p;  
        p=p->next;  
        free(q);  
    }  
}  
  
  
void Add(LinkList &L1,LinkList &L2){  
    //多项式相加  
    LinkList p1=L1->next,p2=L2->next,r1=L1,q;//r1始终指向链表的尾部,p1和p2表示当前结点  
    while(p1&&p2){  
        int n=compare(p1->data,p2->data);  
        switch(n){  
        case -1:{r1->next=p1;r1=p1;p1=p1->next;break;} //L1中的值小，插入之  
        case 1:{r1->next=p2;r1=p2;p2=p2->next;break;}   //L2中的值小，插入之  
        case 0:{    //相同  
                float sum=p1->data.coef+p2->data.coef;  
                if(sum==0){q=p1;p1=p1->next;free(q);} //删除L1中的  
                else{p1->data.coef=sum;  //插入L1中的  
                    r1->next=p1;r1=p1;p1=p1->next;}  
                q=p2;p2=p2->next;free(q);  //统一删除L2中的  
               }  
        }  
    }  
        if(p1)  
            r1->next=p1;  //添加L1  
        else  
            r1->next=p2;  //添加L2  
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
/*#include<iostream>
using namespace std;
template<class T>
struct Node{
	T data;
	int next;
};
template<class T>
class StaLink{
	private:
		T *Elem,*space;
		int max;
		int Malloc();
	public:
		StaLink(int Max);
		~StaLink();
		void Insert(int i,T e);
		T Delete(int i);
		void Display();
		T DataFind(T e);
		T LocaFind(int i);
		T Front(T e);
		T Behind(T e);
		void Empty();
		void Clear();
		void Free(int i);
};
template<class T>
StaLink<T>::StaLink(int Max){
	Elem = new T[Max];
	space = new T[Max];
	max=Max;
	if(!Elem&&!space) throw"内存分配失败";
	for(int i=0;i<Max-1;i++)
		space[i].next=i+1;
	space[Max-1].next=0;
}
template<class T>
int StaLink<T>::Malloc(){
	int i=space[Max-1].next;
	if(space[0].next)
	i=space[0].next;
	space[0].next=space[i].next;
	return i;
}
/*template<class T>
DouLink<T>::~DouLink(){
	Node<T>* p;
	while(head){
	p=head;
	head=head->next;
	delete p;
	}
	head=NULL;
}
//插入数据
template<class T>
void StaLink<T>::Insert(int i,T e){
	int k=max-1;
	if(i<1||i>max)throw"异常";
	int j=StaLink<T>::Malloc();
	if(j){
	Elem[j].data=e;
	for(int m=1;m<i;m++)
		k=Elem[k].next;
	Elem[j].next=Elem[k].next;
	Elem[k].next=j;
	}
}
//删除数据
template<class T>
T StaLink<T>::Delete(int i){
	if(i<1||i>max)throw"异常";
	int k=max-1;
	for(int j=1;j<i;j++)
		k=Elem[k].next;
	j=Elem[k].next;
	Elem[k].next=Elem[j].next;
	StaLink<T>::Free(j);
}
//释放到备用链表
template<class T>
void StaLink<T>::Free(int i){
	Elem[i].next=space[0].next;
	space[0].next=i;
}
//打印数据
/*template<class T>
void DouLink<T>::Display(){
	Node<T> *p=head->next;
	cout<<endl<<"链表里的数据为：";
	while(p){
	cout<<p->data<<"  ";
	p=p->next;
	}
}
//按值查找
template<class T>
T DouLink<T>::DataFind(T e){
	Node<T> *p=head;
	int i=0;
	while(p){
		i++;
		p=p->next;
		if(p->data==e)return i;
		}
	throw"你所查找的值不存在";

}
//按位查找
template<class T>
T DouLink<T>::LocaFind(int i){
	Node<T> *p=head->next;
	int j=1;
	while(j<i&&p){
		p=p->next;
		j++;
		}
	if(!p||j>i)throw"你所查找的值不存在";
	T e=p->data;
	return e;
}
//查找前驱
template<class T>
T DouLink<T>::Front(T e){
	Node<T> *B=head;
	while(B){
		B=B->next;
		if(!B)throw"该元素不存在";
		if(B->data==e){
			if(B==head->next)throw"该元素没有前驱";
			return B->prior->data;}
		
	}
}
//查找后继
template<class T>
T DouLink<T>::Behind(T e){
	Node<T> *A=head;
	Node<T> *B=head->next;
	while(B){
		if(A->data==e)return B->data;
		A=A->next;
		B=B->next;
		if(!B)throw"该元素不存在";
		}
	throw"该元素没有后继";
}
//链表判空
template<class T>
void DouLink<T>::Empty(){
	if(head->next==NULL)
		throw"链表为空";
		cout<<"链表不为空";
}
//链表清空
template<class T>
void DouLink<T>::Clear(){
	Node<T> *p=head->next;
	if(!p)throw"链表为空";
	while(p){
		p=p->next;
		delete p;
		}
	delete p;
}
void Menu(){
	cout<<endl;
	cout<<"\t1  插入 数据\t\t6  查找 前驱\n";
	cout<<"\t2  删除 数据\t\t7  查找 后继\n";
    cout<<"\t3  显示 链表\t\t8  链表 判空\n";
    cout<<"\t4  按值 查找\t\t9  链表 清空\n";
    cout<<"\t5  按位 查找\t\t0  退出     \n";
    
}
int main(){
	StaLink<int> L(100);
	int i,e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:{
		cout<<"请输入插入的数据：";cin>>e;cout<<"请输入插入的位置：";cin>>i;
		try{L.Insert(i,e);
		cout<<endl<<"插入成功！"<<endl;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"请输入删除的位置：";cin>>i;
		try
		{e=L.Delete(i);
		cout<<endl<<"删除成功！删除是数据是"<<e;
		}
		catch(const char *s){
			cout<<s<<endl;}
		}
		break;
	/*case 3:L.Display();break;
	case 4:{
		cout<<"请输入查找的数据：";cin>>e;
		try{
		i=L.DataFind(e);
		cout<<endl<<"数据的位置为"<<i;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 5:{
		cout<<"请输入查找的位置：";cin>>i;
		try{
		e=L.LocaFind(i);
		cout<<endl<<"查找的数据为"<<e;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:{
		cout<<"请输入所查找的前驱数：";cin>>i;
		try{
		e=L.Front(i);cout<<endl<<"查找数据的前驱为"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 7:{
		cout<<"请输入所查找的后继数：";cin>>i;
		try{e=L.Behind(i);cout<<endl<<"查找数据的后继为"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 8:try{L.Empty();}
		catch(const char *s){cout<<s<<endl;} break;
	case 9:try{L.Clear();cout<<"清空成功！";}
		catch(const char *s){cout<<s<<endl;}break;
	default:break;
		}
	}
	return 0;
}*/
#include <iostream>
using namespace std;  
#define MAXSIZE 1000  //设定数组的最大值  
typedef int ElemType; //设定数组的数据类型  
typedef struct{  
    ElemType data; //结点的数据域  
    int cur;  //结点的游标域  
}Node,SLinkList[MAXSIZE];  
void InitList(SLinkList l); //初始化链表  
void InsertList(SLinkList l,int i,ElemType e); //在链表的第i个位置插入元素  
void DeleteList(SLinkList l,int i); //删除链表的第i个元素  
int Malloc_SLL(SLinkList l); //申请空间  
void Free_SLL(SLinkList l); //释放空间  
int GetListLength(SLinkList l); //返回链表的长度  
void Print(SLinkList l); //打印链表  
void InitList(SLinkList l) //初始化链表  
{  
    for(int i = 0;i < MAXSIZE - 1;++i) //初始化链表的游标,使其全部形成链接  
        l[i].cur = i + 1;  
    l[MAXSIZE - 1].cur = 0; //初始化最后一个结点的游标为0  
}  
int Malloc_SLL(SLinkList l) //申请链表的剩余空间  
{  
    int j = l[0].cur;  
    if(l[0].cur)  
        l[0].cur = l[j].cur;  
    return j;  
}  
void Free_SLL(SLinkList l,int j) //释放链表的空间  
{  
    l[j].cur = l[0].cur;  
    l[0].cur = j;  
}  
void InsertList(SLinkList l,int i,ElemType e) //在链表的第i个位置插入元素e  
{  
    if(i < 1 || i > GetListLength(l) + 1) //超出范围退出  
        return;  
    int k = MAXSIZE - 1; //使K为最后一个结点游标  
    for(int j = 0;j < i - 1;++j)   
        k = l[k].cur;  
    int v = Malloc_SLL(l); //申请空间  
    if(v) //如果有空间  
    {  
        l[v].data = e;  
        l[v].cur = l[k].cur;  
        l[k].cur = v;  
    }  
}  
void DeleteList(SLinkList l,int i) //删除第i个位置的元素  
{  
    if(i < 1 || i > GetListLength(l)) //超出范围退出  
        return;  
    int k = MAXSIZE - 1; //K指示链表的最后一个结点  
    for(int j = 0;j < i - 1;++j) //使k指示要删除的结点的前一个结点  
        k = l[k].cur;  
    int temp = l[k].cur;  
    l[k].cur = l[temp].cur;  
    Free_SLL(l,temp);  
}  
int GetListLength(SLinkList l) //返回链表的当前长度  
{  
    int j = 0;  
    int k = l[MAXSIZE - 1].cur;  
    while(k)  
    {  
        ++j;  
        k = l[k].cur;  
    }  
    return j;  
}  
void Print(SLinkList l) //打印链表  
{  
    int k = l[MAXSIZE - 1].cur;  
    while(k)  
    {  
        printf("%d ",l[k].data);  
        k = l[k].cur;  
    }  
    printf("\n");  
}  
void Menu(){
	cout<<endl;
	cout<<"\t1  初始化链表 \n";
	cout<<"\t2  输出链表 \n";
    cout<<"\t3  删除 数据 \n";
	cout<<"\t4  插入 数据 \n";
    
    
}
int main(){
    SLinkList l;
	int i,e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:InitList(l);
		break;
	case 2:Print(l); //输出链表  
		break;
	case 3:{
		   cout<<"\n请输入要删除的位置：";cin>>i;
		   DeleteList(l,i-1);
		   cout<<"\n删除成功";
		   } 
		break;
	case 4:{
		   cout<<"\n请输入要插入的位置：";cin>>i;
			   cout<<"\n请输入要插入的数据：";cin>>e;
			   InsertList(l,i,e);
		   }
		break;
	} 
	}
    return 0;  
}  
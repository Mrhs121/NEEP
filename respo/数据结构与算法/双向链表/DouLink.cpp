#include<iostream>
using namespace std;
template<class T>
struct Node{
	T data;
	Node<T>* prior;
	Node<T>* next;
};
template<class T>
class DouLink{
	private:
		Node<T>* head;
	public:
		DouLink();
		~DouLink();
		void Insert(int i,T e);
		T Delete(int i);
		void Display();
		T DataFind(T e);
		T LocaFind(int i);
		T Front(T e);
		T Behind(T e);
		void Empty();
		void Clear();
};
template<class T>
DouLink<T>::DouLink(){
	head = new Node<T>;
	head->next=head->prior=NULL;
}
template<class T>
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
void DouLink<T>::Insert(int i,T e){
	int j=0;
	Node<T>* p=head;
	while(j<i-1&&p){
	p=p->next;j++;
	}
	if(!p||j>i-1)throw"位置异常";
	Node<T>*s=new Node<T>;
	s->data=e;
	s->prior=p;
	s->next=p->next;
	p->next=s;
}
//删除数据
template<class T>
T DouLink<T>::Delete(int i){
	int j=0;
	Node<T>*p=head;
	while(j<i-1&&p->next){
	p=p->next;j++;
	}
	if(!p->next||j>i-1)throw"位置异常";
	Node<T> *s=p->next;
	T e=s->data;
	/*p->next->next->prior=p->next->prior;
	p->next->next=p->next;*/
	s->next->prior=s->prior;
	p->next=s->next;
	delete s;
	return e;
}
//打印数据
template<class T>
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
	DouLink<int> L;
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
	case 3:L.Display();break;
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
}
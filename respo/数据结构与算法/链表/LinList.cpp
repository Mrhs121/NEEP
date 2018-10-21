#include<iostream>
using namespace std;
template<class T>
struct node{
	T data;
	node *next;
};
template<class T>
class LinkList{
private:
	node<T> *head;
public:
	//创建一个链表
	LinkList(){
	head=new node<T>;
	head->next=NULL;
	}
	//销毁链表
	~LinkList(){
		node<T> *p;
		while(head){
		p=head;head=head->next;
		delete p;
		}
	}

	//插入一个数
	void Insert(T e,int i){
	int j=0;
	node<T> *p=head;
	while(j<i-1&&p){
		p=p->next;j++;
		}
	if(!p||j>i-1)throw"位置异常";
	node<T> *newnode=new node<T>;
	newnode->data=e;
	newnode->next=p->next;
	p->next=newnode;
	}

	//删除一个数
	T Delete(int i){
	int j=0;
	node<T> *p=head;
	while(j<i-1&&p->next){
		p=p->next;
		j++;
		}
	if(!p->next||j>i-1)throw"位置异常";
	node<T> *newnode=p->next;
	T e=newnode->data;
	p->next=newnode->next;
	delete newnode;
	return e;
	}

	//打印链表里的数据
	void Display(){
	node<T> *p=head->next;
	cout<<endl;
	while(p){
		cout<<p->data<<"  ";p=p->next;
		}
	cout<<endl;
	}

	//按值查找
	int DataFind(T e){
	node<T> *p=head;
	int i=0;
	while(p){
		i++;
		p=p->next;
		if(p->data==e)return i;
		}
	throw"你所查找的值不存在";
	}

	//按位置查找
	T LocaFind(int i){
	node<T> *p=head->next;
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
	T Front(T e){
	node<T> *A=head;
	node<T> *B=head->next;
	while(B){
		A=A->next;
		if(B->data==e)return A->data;
		B=B->next;
		}
	throw"该元素没有前驱";
	}

	//查找后继
	T Behind(T e){
	node<T> *A=head;
	node<T> *B=head->next;
	while(B){
		if(A->data==e)return B->data;
		A=A->next;
		B=B->next;
		}
	throw"该元素没有后继";
	}

	//判断表空
	void Empty()
    {
		if(head->next==NULL)
		throw"链表为空";
		cout<<"链表不为空";
	}
	
	//清空链表
	void Clear(){
	node<T> *p=head->next;
	while(p){
		p=p->next;
		delete p;
		}
	}
};

void Menu(){
	cout<<endl;
	cout<<"\t1  插入 数据\t\t6  查找 前驱\n";
	cout<<"\t2  删除 数据\t\t7  查找 后继\n";
    cout<<"\t3  显示 链表\t\t8  链表 判空\n";
    cout<<"\t4  按值 查找\t\t9  链表 清空\n";
    cout<<"\t5  按位 查找\t\t0  退出     \n";
    
}
int main(){
	LinkList<int> L;
	int i,e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:{
		cout<<"请输入插入的数据：";cin>>e;cout<<"请输入插入的位置：";cin>>i;
		try{L.Insert(e,i);
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
	case 9:L.Clear();cout<<"清空成功！";break;
	default:break;
		}
	}
	return 0;
}

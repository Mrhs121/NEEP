#include<iostream>
using namespace std;
template<class T>
struct Node{
	T data;
	Node<T>* next;
};
template<class T>
class LinkQueue{
	private:
		Node<T>* front;
		Node<T>* rear;
	public:
		LinkQueue();			//构造
		~LinkQueue();			//析构
		void EnQueue(T x);		//加入 队列
		T DeQueue();			//删除 元素
		T GetHead();			//取得 队首
		T GetLast();			//取得 队尾
		void QueueEmpty();		//列队  判空
		void ClearQueue();		//清空  队列
		void QueueDisp();	//打印队列元素
};
template<class T>
LinkQueue<T>::LinkQueue(){
	front = new Node<T>;
	front->next = NULL;
	rear=front;
}
template<class T>
LinkQueue<T>::~LinkQueue(){
	Node<T>*p;
	while(front!=NULL){
	p=front;
	front = front->next;
	delete p;
	}
}
//入队
template<class T>
void LinkQueue<T>::EnQueue(T x){
	Node<T>* s;
	s = new Node<T>;
	s->data=x;
	s->next=rear->next;
	rear->next=s;
	rear=s;
}
//出队
template<class T>
T LinkQueue<T>::DeQueue(){
	T x;
	Node<T>*p;
	if(rear==front)throw"下溢";
	p=front->next;
	if(p==NULL){
		rear=front;
		throw"队列已空！";
	}
	x=GetHead();
	front->next=p->next;
	delete p;
	return x;
}
//获得队首
template<class T>
T LinkQueue<T>::GetHead(){
	T x;
	Node<T> *p;
	p=front->next;
	x=p->data;
	return x;
}
//获得队尾
template<class T>
T LinkQueue<T>::GetLast(){
	T x;
	Node<T>*p=front->next;
	while(p!=NULL){
		x=p->data;
		p=p->next;
	}
	return x;
}
//队列判空
template<class T>
void LinkQueue<T>::QueueEmpty(){
	if(front->next==NULL)throw"列队为空";
	else
		cout<<"\n列队不为空";
}
//队列清空
template<class T>
void LinkQueue<T>::ClearQueue(){
	while(front->next!=NULL)
	DeQueue();
		rear=front;
		
}
//队列打印
template<class T>
void LinkQueue<T>::QueueDisp(){
	Node<T>*p=front;
	if(front==rear)throw"队列为空！";
	cout<<"\n队中数据为：";
	while(p->next!=NULL){
		p = p->next;
	cout<<" "<<p->data;
	}
}
void Menu1(){
	cout<<endl;
	cout<<"1  入队      \t";cout<<"2  出队\n";
	
    cout<<"3  显示      \t";cout<<"4  获得队首\n";
    
    cout<<"5  获得队尾  \t";cout<<"6  队列判空\n";//?

	cout<<"0  清空\n";
}
void Menu2(){
	LinkQueue<int> L;
	int i,e;
	while(1){
	Menu1();
	int Choose;cin>>Choose;
	switch(Choose){
	case 1:{
		   cout<<"\n\t\t请输入入队的数据：";cin>>e;
		   	try{
				L.EnQueue(e);
				cout<<endl<<"入队成功！"<<endl;
				}
			catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		try{
			e=L.DeQueue();
			cout<<endl<<"出队成功！出队的数据是"<<e;
			}
		catch(const char *s){cout<<s<<endl;}
		}break;
	case 3:{
		L.QueueDisp();
		   }break;
	case 4:{
		int x;
		try{x=L.GetHead();
		cout<<"\n该队列的队首是："<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 5:{
		int x;
		try{x=L.GetLast();
		cout<<"\n该队列的队尾是："<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:try{L.QueueEmpty();}
		catch(const char *s){cout<<s<<endl;}
		break;
	case 0:{
		   L.ClearQueue();
		   cout<<"\n数据表已清空";
		   }break;
	default:break;

		}
	}
}
void main(){
	Menu2();
}

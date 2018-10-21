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
		LinkQueue();			//����
		~LinkQueue();			//����
		void EnQueue(T x);		//���� ����
		T DeQueue();			//ɾ�� Ԫ��
		T GetHead();			//ȡ�� ����
		T GetLast();			//ȡ�� ��β
		void QueueEmpty();		//�ж�  �п�
		void ClearQueue();		//���  ����
		void QueueDisp();	//��ӡ����Ԫ��
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
//���
template<class T>
void LinkQueue<T>::EnQueue(T x){
	Node<T>* s;
	s = new Node<T>;
	s->data=x;
	s->next=rear->next;
	rear->next=s;
	rear=s;
}
//����
template<class T>
T LinkQueue<T>::DeQueue(){
	T x;
	Node<T>*p;
	if(rear==front)throw"����";
	p=front->next;
	if(p==NULL){
		rear=front;
		throw"�����ѿգ�";
	}
	x=GetHead();
	front->next=p->next;
	delete p;
	return x;
}
//��ö���
template<class T>
T LinkQueue<T>::GetHead(){
	T x;
	Node<T> *p;
	p=front->next;
	x=p->data;
	return x;
}
//��ö�β
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
//�����п�
template<class T>
void LinkQueue<T>::QueueEmpty(){
	if(front->next==NULL)throw"�ж�Ϊ��";
	else
		cout<<"\n�жӲ�Ϊ��";
}
//�������
template<class T>
void LinkQueue<T>::ClearQueue(){
	while(front->next!=NULL)
	DeQueue();
		rear=front;
		
}
//���д�ӡ
template<class T>
void LinkQueue<T>::QueueDisp(){
	Node<T>*p=front;
	if(front==rear)throw"����Ϊ�գ�";
	cout<<"\n��������Ϊ��";
	while(p->next!=NULL){
		p = p->next;
	cout<<" "<<p->data;
	}
}
void Menu1(){
	cout<<endl;
	cout<<"1  ���      \t";cout<<"2  ����\n";
	
    cout<<"3  ��ʾ      \t";cout<<"4  ��ö���\n";
    
    cout<<"5  ��ö�β  \t";cout<<"6  �����п�\n";//?

	cout<<"0  ���\n";
}
void Menu2(){
	LinkQueue<int> L;
	int i,e;
	while(1){
	Menu1();
	int Choose;cin>>Choose;
	switch(Choose){
	case 1:{
		   cout<<"\n\t\t��������ӵ����ݣ�";cin>>e;
		   	try{
				L.EnQueue(e);
				cout<<endl<<"��ӳɹ���"<<endl;
				}
			catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		try{
			e=L.DeQueue();
			cout<<endl<<"���ӳɹ������ӵ�������"<<e;
			}
		catch(const char *s){cout<<s<<endl;}
		}break;
	case 3:{
		L.QueueDisp();
		   }break;
	case 4:{
		int x;
		try{x=L.GetHead();
		cout<<"\n�ö��еĶ����ǣ�"<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 5:{
		int x;
		try{x=L.GetLast();
		cout<<"\n�ö��еĶ�β�ǣ�"<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:try{L.QueueEmpty();}
		catch(const char *s){cout<<s<<endl;}
		break;
	case 0:{
		   L.ClearQueue();
		   cout<<"\n���ݱ������";
		   }break;
	default:break;

		}
	}
}
void main(){
	Menu2();
}

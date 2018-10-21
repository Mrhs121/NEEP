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
//��������
template<class T>
void DouLink<T>::Insert(int i,T e){
	int j=0;
	Node<T>* p=head;
	while(j<i-1&&p){
	p=p->next;j++;
	}
	if(!p||j>i-1)throw"λ���쳣";
	Node<T>*s=new Node<T>;
	s->data=e;
	s->prior=p;
	s->next=p->next;
	p->next=s;
}
//ɾ������
template<class T>
T DouLink<T>::Delete(int i){
	int j=0;
	Node<T>*p=head;
	while(j<i-1&&p->next){
	p=p->next;j++;
	}
	if(!p->next||j>i-1)throw"λ���쳣";
	Node<T> *s=p->next;
	T e=s->data;
	/*p->next->next->prior=p->next->prior;
	p->next->next=p->next;*/
	s->next->prior=s->prior;
	p->next=s->next;
	delete s;
	return e;
}
//��ӡ����
template<class T>
void DouLink<T>::Display(){
	Node<T> *p=head->next;
	cout<<endl<<"�����������Ϊ��";
	while(p){
	cout<<p->data<<"  ";
	p=p->next;
	}
}
//��ֵ����
template<class T>
T DouLink<T>::DataFind(T e){
	Node<T> *p=head;
	int i=0;
	while(p){
		i++;
		p=p->next;
		if(p->data==e)return i;
		}
	throw"�������ҵ�ֵ������";

}
//��λ����
template<class T>
T DouLink<T>::LocaFind(int i){
	Node<T> *p=head->next;
	int j=1;
	while(j<i&&p){
		p=p->next;
		j++;
		}
	if(!p||j>i)throw"�������ҵ�ֵ������";
	T e=p->data;
	return e;
}
//����ǰ��
template<class T>
T DouLink<T>::Front(T e){
	Node<T> *B=head;
	while(B){
		B=B->next;
		if(!B)throw"��Ԫ�ز�����";
		if(B->data==e){
			if(B==head->next)throw"��Ԫ��û��ǰ��";
			return B->prior->data;}
		
	}
}
//���Һ��
template<class T>
T DouLink<T>::Behind(T e){
	Node<T> *A=head;
	Node<T> *B=head->next;
	while(B){
		if(A->data==e)return B->data;
		A=A->next;
		B=B->next;
		if(!B)throw"��Ԫ�ز�����";
		}
	throw"��Ԫ��û�к��";
}
//�����п�
template<class T>
void DouLink<T>::Empty(){
	if(head->next==NULL)
		throw"����Ϊ��";
		cout<<"����Ϊ��";
}
//�������
template<class T>
void DouLink<T>::Clear(){
	Node<T> *p=head->next;
	if(!p)throw"����Ϊ��";
	while(p){
		p=p->next;
		delete p;
		}
	delete p;
}
void Menu(){
	cout<<endl;
	cout<<"\t1  ���� ����\t\t6  ���� ǰ��\n";
	cout<<"\t2  ɾ�� ����\t\t7  ���� ���\n";
    cout<<"\t3  ��ʾ ����\t\t8  ���� �п�\n";
    cout<<"\t4  ��ֵ ����\t\t9  ���� ���\n";
    cout<<"\t5  ��λ ����\t\t0  �˳�     \n";
    
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
		cout<<"�������������ݣ�";cin>>e;cout<<"����������λ�ã�";cin>>i;
		try{L.Insert(i,e);
		cout<<endl<<"����ɹ���"<<endl;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"������ɾ����λ�ã�";cin>>i;
		try
		{e=L.Delete(i);
		cout<<endl<<"ɾ���ɹ���ɾ����������"<<e;
		}
		catch(const char *s){
			cout<<s<<endl;}
		}
		break;
	case 3:L.Display();break;
	case 4:{
		cout<<"��������ҵ����ݣ�";cin>>e;
		try{
		i=L.DataFind(e);
		cout<<endl<<"���ݵ�λ��Ϊ"<<i;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 5:{
		cout<<"��������ҵ�λ�ã�";cin>>i;
		try{
		e=L.LocaFind(i);
		cout<<endl<<"���ҵ�����Ϊ"<<e;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:{
		cout<<"�����������ҵ�ǰ������";cin>>i;
		try{
		e=L.Front(i);cout<<endl<<"�������ݵ�ǰ��Ϊ"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 7:{
		cout<<"�����������ҵĺ������";cin>>i;
		try{e=L.Behind(i);cout<<endl<<"�������ݵĺ��Ϊ"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 8:try{L.Empty();}
		catch(const char *s){cout<<s<<endl;} break;
	case 9:try{L.Clear();cout<<"��ճɹ���";}
		catch(const char *s){cout<<s<<endl;}break;
	default:break;
		}
	}
	return 0;
}
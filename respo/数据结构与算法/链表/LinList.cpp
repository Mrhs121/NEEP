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
	//����һ������
	LinkList(){
	head=new node<T>;
	head->next=NULL;
	}
	//��������
	~LinkList(){
		node<T> *p;
		while(head){
		p=head;head=head->next;
		delete p;
		}
	}

	//����һ����
	void Insert(T e,int i){
	int j=0;
	node<T> *p=head;
	while(j<i-1&&p){
		p=p->next;j++;
		}
	if(!p||j>i-1)throw"λ���쳣";
	node<T> *newnode=new node<T>;
	newnode->data=e;
	newnode->next=p->next;
	p->next=newnode;
	}

	//ɾ��һ����
	T Delete(int i){
	int j=0;
	node<T> *p=head;
	while(j<i-1&&p->next){
		p=p->next;
		j++;
		}
	if(!p->next||j>i-1)throw"λ���쳣";
	node<T> *newnode=p->next;
	T e=newnode->data;
	p->next=newnode->next;
	delete newnode;
	return e;
	}

	//��ӡ�����������
	void Display(){
	node<T> *p=head->next;
	cout<<endl;
	while(p){
		cout<<p->data<<"  ";p=p->next;
		}
	cout<<endl;
	}

	//��ֵ����
	int DataFind(T e){
	node<T> *p=head;
	int i=0;
	while(p){
		i++;
		p=p->next;
		if(p->data==e)return i;
		}
	throw"�������ҵ�ֵ������";
	}

	//��λ�ò���
	T LocaFind(int i){
	node<T> *p=head->next;
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
	T Front(T e){
	node<T> *A=head;
	node<T> *B=head->next;
	while(B){
		A=A->next;
		if(B->data==e)return A->data;
		B=B->next;
		}
	throw"��Ԫ��û��ǰ��";
	}

	//���Һ��
	T Behind(T e){
	node<T> *A=head;
	node<T> *B=head->next;
	while(B){
		if(A->data==e)return B->data;
		A=A->next;
		B=B->next;
		}
	throw"��Ԫ��û�к��";
	}

	//�жϱ��
	void Empty()
    {
		if(head->next==NULL)
		throw"����Ϊ��";
		cout<<"����Ϊ��";
	}
	
	//�������
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
	cout<<"\t1  ���� ����\t\t6  ���� ǰ��\n";
	cout<<"\t2  ɾ�� ����\t\t7  ���� ���\n";
    cout<<"\t3  ��ʾ ����\t\t8  ���� �п�\n";
    cout<<"\t4  ��ֵ ����\t\t9  ���� ���\n";
    cout<<"\t5  ��λ ����\t\t0  �˳�     \n";
    
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
		cout<<"�������������ݣ�";cin>>e;cout<<"����������λ�ã�";cin>>i;
		try{L.Insert(e,i);
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
	case 9:L.Clear();cout<<"��ճɹ���";break;
	default:break;
		}
	}
	return 0;
}

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
	if(!Elem&&!space) throw"�ڴ����ʧ��";
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
//��������
template<class T>
void StaLink<T>::Insert(int i,T e){
	int k=max-1;
	if(i<1||i>max)throw"�쳣";
	int j=StaLink<T>::Malloc();
	if(j){
	Elem[j].data=e;
	for(int m=1;m<i;m++)
		k=Elem[k].next;
	Elem[j].next=Elem[k].next;
	Elem[k].next=j;
	}
}
//ɾ������
template<class T>
T StaLink<T>::Delete(int i){
	if(i<1||i>max)throw"�쳣";
	int k=max-1;
	for(int j=1;j<i;j++)
		k=Elem[k].next;
	j=Elem[k].next;
	Elem[k].next=Elem[j].next;
	StaLink<T>::Free(j);
}
//�ͷŵ���������
template<class T>
void StaLink<T>::Free(int i){
	Elem[i].next=space[0].next;
	space[0].next=i;
}
//��ӡ����
/*template<class T>
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
	StaLink<int> L(100);
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
	/*case 3:L.Display();break;
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
}*/
#include <iostream>
using namespace std;  
#define MAXSIZE 1000  //�趨��������ֵ  
typedef int ElemType; //�趨�������������  
typedef struct{  
    ElemType data; //����������  
    int cur;  //�����α���  
}Node,SLinkList[MAXSIZE];  
void InitList(SLinkList l); //��ʼ������  
void InsertList(SLinkList l,int i,ElemType e); //������ĵ�i��λ�ò���Ԫ��  
void DeleteList(SLinkList l,int i); //ɾ������ĵ�i��Ԫ��  
int Malloc_SLL(SLinkList l); //����ռ�  
void Free_SLL(SLinkList l); //�ͷſռ�  
int GetListLength(SLinkList l); //��������ĳ���  
void Print(SLinkList l); //��ӡ����  
void InitList(SLinkList l) //��ʼ������  
{  
    for(int i = 0;i < MAXSIZE - 1;++i) //��ʼ��������α�,ʹ��ȫ���γ�����  
        l[i].cur = i + 1;  
    l[MAXSIZE - 1].cur = 0; //��ʼ�����һ�������α�Ϊ0  
}  
int Malloc_SLL(SLinkList l) //���������ʣ��ռ�  
{  
    int j = l[0].cur;  
    if(l[0].cur)  
        l[0].cur = l[j].cur;  
    return j;  
}  
void Free_SLL(SLinkList l,int j) //�ͷ�����Ŀռ�  
{  
    l[j].cur = l[0].cur;  
    l[0].cur = j;  
}  
void InsertList(SLinkList l,int i,ElemType e) //������ĵ�i��λ�ò���Ԫ��e  
{  
    if(i < 1 || i > GetListLength(l) + 1) //������Χ�˳�  
        return;  
    int k = MAXSIZE - 1; //ʹKΪ���һ������α�  
    for(int j = 0;j < i - 1;++j)   
        k = l[k].cur;  
    int v = Malloc_SLL(l); //����ռ�  
    if(v) //����пռ�  
    {  
        l[v].data = e;  
        l[v].cur = l[k].cur;  
        l[k].cur = v;  
    }  
}  
void DeleteList(SLinkList l,int i) //ɾ����i��λ�õ�Ԫ��  
{  
    if(i < 1 || i > GetListLength(l)) //������Χ�˳�  
        return;  
    int k = MAXSIZE - 1; //Kָʾ��������һ�����  
    for(int j = 0;j < i - 1;++j) //ʹkָʾҪɾ���Ľ���ǰһ�����  
        k = l[k].cur;  
    int temp = l[k].cur;  
    l[k].cur = l[temp].cur;  
    Free_SLL(l,temp);  
}  
int GetListLength(SLinkList l) //��������ĵ�ǰ����  
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
void Print(SLinkList l) //��ӡ����  
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
	cout<<"\t1  ��ʼ������ \n";
	cout<<"\t2  ������� \n";
    cout<<"\t3  ɾ�� ���� \n";
	cout<<"\t4  ���� ���� \n";
    
    
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
	case 2:Print(l); //�������  
		break;
	case 3:{
		   cout<<"\n������Ҫɾ����λ�ã�";cin>>i;
		   DeleteList(l,i-1);
		   cout<<"\nɾ���ɹ�";
		   } 
		break;
	case 4:{
		   cout<<"\n������Ҫ�����λ�ã�";cin>>i;
			   cout<<"\n������Ҫ��������ݣ�";cin>>e;
			   InsertList(l,i,e);
		   }
		break;
	} 
	}
    return 0;  
}  
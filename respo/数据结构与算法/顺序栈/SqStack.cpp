#include<iostream>
using namespace std;
template<class T>
class SqStack{
	private:
		T *base;				
		int top;				//��¼��ǰջ��
		int stacksize;			//��ǵ�ǰջ������
	public:
		SqStack(int m);			//����һ��ջ��Ϊm�Ŀ�ջ
		~SqStack();				//����ջ
		void Insert(T e);		//��ջ
		T Delete();				//��ջ
		T GetTop();				//���ջ��Ԫ��
		//int Locate(T e);		//Ԫ�ض�λ
		void Clear();			//���ջ
		void Empty();			//��ջ��
		void StackDisp();		//��ӡ����е�Ԫ��
		T Front(T e);			//����Ԫ��ǰ��
		T Behind(T e);			//����Ԫ�غ��
};
template<class T>
SqStack<T>::SqStack(int m){
	base=new T[m];
	if(base==NULL){
	cout<<"��ջʧ��"<<endl;
	exit(1);
	}
	stacksize=m;
	top=0;
}
template<class T>
SqStack<T>::~SqStack(){
	delete []base;
	top=-1;
	stacksize=0;
}
//��ջ
template<class T>
void SqStack<T>::Insert(T e){
	if(top==stacksize)throw"ջ�����޷���ջ";
	base[top]=e;
	top++;
}
//��ջ
template<class T>
T SqStack<T>::Delete(){
	int m=top-1;
	if(top==0)throw"ջ���޷���ջ";
	return base[m];
}
//���ջ��
template<class T>
T SqStack<T>::GetTop(){
	if(top==0)throw"ջ��,��ջ��Ԫ��";
	return base[top];
}
//���ջ
template<class T>
void SqStack<T>::Clear(){
	while(top!=0)
	Delete();
	
}
//��ջ��
template<class T>
void SqStack<T>::Empty(){
	if(top==0)
		cout<<"\nջ��";
	else 
		cout<<"\nջ��������";
}
//��ӡջ��Ԫ��
template<class T>
void SqStack<T>::StackDisp(){
	if(top!=0){
		cout<<"\nջ��Ԫ��Ϊ��";
		int m=top;
		while(m!=0){
			m--;
	cout<<" "<<base[m];
		}
	}
	else
		cout<<"\nջ�գ�������";
}
//����ǰ��
template<class T>
T SqStack<T>::Front(T e){
	int m=top;
	while(m!=0){
		cout<<m;
		if(base[m-1]==e){
			if(m<=1)throw"ջ�ף���ǰ����";
			return base[m-2];}
		m--;
	}

}
//���Һ��
template<class T>
T SqStack<T>::Behind(T e){
	int m=top;
	if(top!=stacksize)
	while(m!=0){
		if(base[m-1]==e){
			if(m==top)throw"ջ�����޺�̣�";
			return base[m];}
		m--;
	}
	else
		cout<<"\nջ�����޺��";
}
void Menu1(){
	cout<<endl;
	cout<<"1  ��ջ      \t";cout<<"2  ��ջ\n";
	
    cout<<"3  ��ʾ      \t";cout<<"4  Ԫ��ǰ��\n";
    
    cout<<"5  Ԫ�غ��  \t";cout<<"6  ����пգ�\n";//?

	cout<<"7  ���ջ��Ԫ��\t";cout<<"0  ���\n";
    
    
    
     
}
void Menu2(){
	SqStack<int> L(100);
	int i,e;
	while(1){
	Menu1();
	int Choose;cin>>Choose;
	switch(Choose){
	case 1:{
		   cout<<"\n\t\t��������ջ�����ݣ�";cin>>e;
		   	try{
				L.Insert(e);
				cout<<endl<<"��ջ�ɹ���"<<endl;
				}
			catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		try{
			e=L.Delete();
			cout<<endl<<"��ջ�ɹ�����ջ��������"<<e;
			}
		catch(const char *s){cout<<s<<endl;}
		}break;
	case 3:{
		L.StackDisp();
		   }break;
	case 4:{
		int x;
		cout<<"\n\t\t�������ѯ�����ݣ�";cin>>e;
		try{x=L.Front(e);
		cout<<"\n�����ݵ�ǰ���ǣ�"<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 5:{
		int x;
		cout<<"\n\t\t�������ѯ�����ݣ�";cin>>e;
		try{x=L.Behind(e);
		cout<<"\n�����ݵĺ���ǣ�"<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:L.Empty();break;
	case 7:{
		   e=L.GetTop();
		   cout<<"\n���и�Ԫ��Ϊ:"<<e;
		   }break;
		  
	case 0:{
		   L.Clear();
		   cout<<"\n���ݱ������";
		   }break;
	default:break;

		}
	}
}
void main(){
	Menu2();
}

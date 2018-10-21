#include<iostream>
using namespace std;
/*template<class T>
struct node{
	T data;
	node *next;
};*/
template<class T>
class StackList{
private:
	T *base;
	int top;
	int stacksize;
public:
	StackList(int n){
	base = new T[n];top = -1; stacksize = n;
	}
	~StackList(){
	delete []base;
	}
	void Insert(T  e){
  
      if(top==stacksize-1)throw"man,buneng jinzhan!\n";      
      base[top+1]=e;
      top++;
       
  }
  T Delete(){
  
         if(top==-1)throw"kong ,buneng chuzhan!\n";
         top--;
         return base[top+1];
  }
  T GetElem(){ 
   
            if(top==-1)throw"kong ,wu zhanding!\n";
            return base[top];
	}
 void display(){
     cout<<"ջ��\n"; 
      for(int i=top;i>=0;i--)
         cout<<"\t"<<base[i]<<endl;
      cout<<"ջ��\n";   
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
	StackList<int> L(100);
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
		}break;
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
		try{
			e=L.Behind(i);cout<<endl<<"�������ݵĺ��Ϊ"<<e;
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
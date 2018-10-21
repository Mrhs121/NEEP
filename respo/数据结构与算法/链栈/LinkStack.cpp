#include<iostream>
using namespace std;
template<class T>
struct node
{
  T data;
  node<T>  * next;         
};

template<class T>
class linkstack
{
    node<T>*top ;
 public:  
//===============�����ʼ��
    linkstack(int n) {
      top= NULL;         
    }
//==============����
    ~linkstack(){
		node<T>*p;
       while(top){
        p=top; 
        top=p->next; 
        delete p ; 
       }     
        //top=NULL;
    }  

//============���
  void push(T  e){
      //if(top==stacksize-1)throw"man,buneng jinzhan!\n";      
      node<T>* s= new node<T> ;
      s->data=e;
      s->next=top;
      top=s;
	}
  //===========ɾ��
  T pop(T e){ 
         if(!top)throw"zhankong ,buneng chuzhan\n!";
         node<T>*s=top;
         e=s->data;
         top=top->next;         
         delete s;
         return e;
  }
  //=============�����Ԫ��
  T gettop(){
         if(top==NULL)throw"kong ,wu zhanding!\n";
         return top->data;
  }
  //=============�п�
  void StackEmpty(){
	if(top==NULL)throw"����Ϊ��";
	cout<<"����Ϊ��\n";
  }
  //=============���
  void ClearStack(){
	  node<T>*p;
        while(top){
         p=top; 
         top=p->next; 
         delete p ;
        } 
       // top=NULL;
    }  
 //============��ʾ��ӡ
 void Display(){
	 node<T>*p;
     cout<<"ջ��\n"; 
      p=top;
      while(p)//û���꡶=��û��ջ�׵����� 
      {
        cout<<"\t"<<p->data<<endl;
        p=p->next;
      }      
      cout<<"ջ��\n"; 
	}
};
void Menu(){
	cout<<endl;
	cout<<"\t1  ��ջ\n";
	cout<<"\t2  ��ջ\n";
    cout<<"\t3  �����Ԫ��\n";
    cout<<"\t4  �п�\n";
    cout<<"\t5  ���\n";
	cout<<"\t6  ��ӡ\n";
    
}
int main()
{
	linkstack<int> L(10);
	int e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:{
		cout<<"��������ջ�����ݣ�";cin>>e;
		L.push(e);
		cout<<endl<<"����ɹ���"<<endl;
		//catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"�������ջ��";cin>>e;
		e=L.pop(e);
		cout<<endl<<"ɾ���ɹ���ɾ����������"<<e;
		
		/*catch(const char *s){
			cout<<s<<endl;}*/
		}
		break;

	case 3:{
		try{
			cout<<"ջ��Ԫ��Ϊ:"<<L.gettop();}
		catch(const char *s){cout<<s<<endl;}
		   }break;


	case 4:try{L.StackEmpty();}
		catch(const char *s){cout<<s<<endl;} break;

	case 5:L.ClearStack();cout<<"��ճɹ���";break;

	case 6:L.Display();break;
	/*case 7:{
		cout<<"�����������ҵĺ������";cin>>i;
		try{e=L.Behind(i);cout<<endl<<"�������ݵĺ��Ϊ"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 8:try{L.Empty();}
		catch(const char *s){cout<<s<<endl;} break;
	case 9:L.Clear();cout<<"��ճɹ���";break;*/
	default:break;
		}
	}
	return 0;
}
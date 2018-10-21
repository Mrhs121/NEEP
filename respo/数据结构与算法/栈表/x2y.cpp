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
    linkstack() {
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
     //cout<<"ջ��\n"; 
      p=top;
      while(p)//û���꡶=��û��ջ�׵����� 
      {
        cout<<"\t"<<p->data<<endl;
        p=p->next;
      }      
     // cout<<"ջ��\n"; 
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
	linkstack<int> L;
	int j=0;
	double e;
  cin>>e;
  int x=int(e);
  double y=e-x;
   do{
      L.push(x%2);
	  x=x/2;
   }while(x);
linkstack<int> K;
	do{
		y=y*2;
      K.push(int(y));
		j++
   }while(y||j==8);
	linkstack<int> M;
	while(!K.StackEmpty()){
		M.push(K.pop());}
   L.Display();cout<<".";K.Display();

	return 0;
}
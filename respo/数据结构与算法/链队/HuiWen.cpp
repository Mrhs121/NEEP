#include<iostream>
#include<string>
using namespace std;
template<class T>
struct node
{
  T data;
  node<T>  * next;         
};

template<class T>
class LinkList
{
    node<T>*top ;
 public:  
//===============�����ʼ��
    LinkList() {
      top= NULL;         
    }
//==============����
    ~LinkList(){
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
int main(){ 
	LinkList<int> L;
	int i=0;
	char* E[i];
	int m,j=0;
	for(i=0;i++;){
		cin>>E[i];
	}
		while(E[j]!='\0'&&E[j]!='&'){
		L.push(E[j]);
		j++;
		m=j;
	}
		while(m==i){
			if(strcmp(E[m],L.pop())!=0)return 0;
			m++;
		}
	cout<<"\n�ǻ���";
}
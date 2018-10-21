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
//===============构造初始化
    LinkList() {
      top= NULL;         
    }
//==============析构
    ~LinkList(){
		node<T>*p;
       while(top){
        p=top; 
        top=p->next; 
        delete p ; 
       }     
        //top=NULL;
    }  

//============添加
  void push(T  e){
      //if(top==stacksize-1)throw"man,buneng jinzhan!\n";      
      node<T>* s= new node<T> ;
      s->data=e;
      s->next=top;
      top=s;
	}
  //===========删除
  T pop(T e){ 
         if(!top)throw"zhankong ,buneng chuzhan\n!";
         node<T>*s=top;
         e=s->data;
         top=top->next;         
         delete s;
         return e;
  }
  //=============获得首元素
  T gettop(){
         if(top==NULL)throw"kong ,wu zhanding!\n";
         return top->data;
  }
  //=============判空
  void StackEmpty(){
	if(top==NULL)throw"链表为空";
	cout<<"链表不为空\n";
  }
  //=============清空
  void ClearStack(){
	  node<T>*p;
        while(top){
         p=top; 
         top=p->next; 
         delete p ;
        } 
       // top=NULL;
    }  
 //============显示打印
 void Display(){
	 node<T>*p;
     cout<<"栈顶\n"; 
      p=top;
      while(p)//没输完《=》没到栈底的下面 
      {
        cout<<"\t"<<p->data<<endl;
        p=p->next;
      }      
      cout<<"栈底\n"; 
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
	cout<<"\n是回文";
}
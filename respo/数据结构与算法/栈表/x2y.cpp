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
//===============构造初始化
    linkstack() {
      top= NULL;         
    }
//==============析构
    ~linkstack(){
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
     //cout<<"栈顶\n"; 
      p=top;
      while(p)//没输完《=》没到栈底的下面 
      {
        cout<<"\t"<<p->data<<endl;
        p=p->next;
      }      
     // cout<<"栈底\n"; 
	}
};
void Menu(){
	cout<<endl;
	cout<<"\t1  入栈\n";
	cout<<"\t2  出栈\n";
    cout<<"\t3  获得首元素\n";
    cout<<"\t4  判空\n";
    cout<<"\t5  清空\n";
	cout<<"\t6  打印\n";
    
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
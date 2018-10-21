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
    linkstack(int n) {
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
	linkstack<int> L(10);
	int e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:{
		cout<<"请输入入栈的数据：";cin>>e;
		L.push(e);
		cout<<endl<<"插入成功！"<<endl;
		//catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"请输入出栈：";cin>>e;
		e=L.pop(e);
		cout<<endl<<"删除成功！删除是数据是"<<e;
		
		/*catch(const char *s){
			cout<<s<<endl;}*/
		}
		break;

	case 3:{
		try{
			cout<<"栈顶元素为:"<<L.gettop();}
		catch(const char *s){cout<<s<<endl;}
		   }break;


	case 4:try{L.StackEmpty();}
		catch(const char *s){cout<<s<<endl;} break;

	case 5:L.ClearStack();cout<<"清空成功！";break;

	case 6:L.Display();break;
	/*case 7:{
		cout<<"请输入所查找的后继数：";cin>>i;
		try{e=L.Behind(i);cout<<endl<<"查找数据的后继为"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 8:try{L.Empty();}
		catch(const char *s){cout<<s<<endl;} break;
	case 9:L.Clear();cout<<"清空成功！";break;*/
	default:break;
		}
	}
	return 0;
}
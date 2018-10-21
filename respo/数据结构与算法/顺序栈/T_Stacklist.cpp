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
     cout<<"栈顶\n"; 
      for(int i=top;i>=0;i--)
         cout<<"\t"<<base[i]<<endl;
      cout<<"栈底\n";   
      }
 
};

void Menu(){
	cout<<endl;
	cout<<"\t1  插入 数据\t\t6  查找 前驱\n";
	cout<<"\t2  删除 数据\t\t7  查找 后继\n";
    cout<<"\t3  显示 链表\t\t8  链表 判空\n";
    cout<<"\t4  按值 查找\t\t9  链表 清空\n";
    cout<<"\t5  按位 查找\t\t0  退出     \n";
    
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
		cout<<"请输入插入的数据：";cin>>e;cout<<"请输入插入的位置：";cin>>i;
		try{L.Insert(e,i);
		cout<<endl<<"插入成功！"<<endl;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"请输入删除的位置：";cin>>i;
		try
		{e=L.Delete(i);
		cout<<endl<<"删除成功！删除是数据是"<<e;
		}
		catch(const char *s){
			cout<<s<<endl;}
		}break;
	case 3:L.Display();break;
	case 4:{
		cout<<"请输入查找的数据：";cin>>e;
		try{
		i=L.DataFind(e);
		cout<<endl<<"数据的位置为"<<i;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 5:{
		cout<<"请输入查找的位置：";cin>>i;
		try{
		e=L.LocaFind(i);
		cout<<endl<<"查找的数据为"<<e;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:{
		cout<<"请输入所查找的前驱数：";cin>>i;
		try{
		e=L.Front(i);cout<<endl<<"查找数据的前驱为"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 7:{
		cout<<"请输入所查找的后继数：";cin>>i;
		try{
			e=L.Behind(i);cout<<endl<<"查找数据的后继为"<<e;
		}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 8:try{L.Empty();}
		catch(const char *s){cout<<s<<endl;} break;
	case 9:L.Clear();cout<<"清空成功！";break;
	default:break;
		}
	}
	return 0;
}
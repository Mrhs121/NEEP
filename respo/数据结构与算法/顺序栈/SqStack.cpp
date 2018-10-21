#include<iostream>
using namespace std;
template<class T>
class SqStack{
	private:
		T *base;				
		int top;				//记录当前栈顶
		int stacksize;			//标记当前栈的容量
	public:
		SqStack(int m);			//创建一个栈长为m的空栈
		~SqStack();				//析构栈
		void Insert(T e);		//入栈
		T Delete();				//出栈
		T GetTop();				//获得栈顶元素
		//int Locate(T e);		//元素定位
		void Clear();			//清空栈
		void Empty();			//测栈空
		void StackDisp();		//打印序表中的元素
		T Front(T e);			//查找元素前驱
		T Behind(T e);			//查找元素后继
};
template<class T>
SqStack<T>::SqStack(int m){
	base=new T[m];
	if(base==NULL){
	cout<<"建栈失败"<<endl;
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
//入栈
template<class T>
void SqStack<T>::Insert(T e){
	if(top==stacksize)throw"栈满，无法入栈";
	base[top]=e;
	top++;
}
//出栈
template<class T>
T SqStack<T>::Delete(){
	int m=top-1;
	if(top==0)throw"栈空无法出栈";
	return base[m];
}
//获得栈顶
template<class T>
T SqStack<T>::GetTop(){
	if(top==0)throw"栈空,无栈顶元素";
	return base[top];
}
//清空栈
template<class T>
void SqStack<T>::Clear(){
	while(top!=0)
	Delete();
	
}
//测栈空
template<class T>
void SqStack<T>::Empty(){
	if(top==0)
		cout<<"\n栈空";
	else 
		cout<<"\n栈中有数据";
}
//打印栈表元素
template<class T>
void SqStack<T>::StackDisp(){
	if(top!=0){
		cout<<"\n栈中元素为：";
		int m=top;
		while(m!=0){
			m--;
	cout<<" "<<base[m];
		}
	}
	else
		cout<<"\n栈空，无数据";
}
//查找前驱
template<class T>
T SqStack<T>::Front(T e){
	int m=top;
	while(m!=0){
		cout<<m;
		if(base[m-1]==e){
			if(m<=1)throw"栈底，无前驱！";
			return base[m-2];}
		m--;
	}

}
//查找后继
template<class T>
T SqStack<T>::Behind(T e){
	int m=top;
	if(top!=stacksize)
	while(m!=0){
		if(base[m-1]==e){
			if(m==top)throw"栈顶，无后继！";
			return base[m];}
		m--;
	}
	else
		cout<<"\n栈满，无后继";
}
void Menu1(){
	cout<<endl;
	cout<<"1  入栈      \t";cout<<"2  出栈\n";
	
    cout<<"3  显示      \t";cout<<"4  元素前驱\n";
    
    cout<<"5  元素后继  \t";cout<<"6  序表判空？\n";//?

	cout<<"7  获得栈顶元素\t";cout<<"0  清空\n";
    
    
    
     
}
void Menu2(){
	SqStack<int> L(100);
	int i,e;
	while(1){
	Menu1();
	int Choose;cin>>Choose;
	switch(Choose){
	case 1:{
		   cout<<"\n\t\t请输入入栈的数据：";cin>>e;
		   	try{
				L.Insert(e);
				cout<<endl<<"入栈成功！"<<endl;
				}
			catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		try{
			e=L.Delete();
			cout<<endl<<"出栈成功！出栈的数据是"<<e;
			}
		catch(const char *s){cout<<s<<endl;}
		}break;
	case 3:{
		L.StackDisp();
		   }break;
	case 4:{
		int x;
		cout<<"\n\t\t请输入查询的数据：";cin>>e;
		try{x=L.Front(e);
		cout<<"\n该数据的前驱是："<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 5:{
		int x;
		cout<<"\n\t\t请输入查询的数据：";cin>>e;
		try{x=L.Behind(e);
		cout<<"\n该数据的后继是："<<x;}
		catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:L.Empty();break;
	case 7:{
		   e=L.GetTop();
		   cout<<"\n表中该元素为:"<<e;
		   }break;
		  
	case 0:{
		   L.Clear();
		   cout<<"\n数据表已清空";
		   }break;
	default:break;

		}
	}
}
void main(){
	Menu2();
}

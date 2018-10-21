#include<iostream>
using namespace std;
template<class T>
class SqList{
	private:
		T *elem;				
		int length;				//记录当前元素个数
		int listsize;			//标记当前序表的容量
	public:
		SqList(int m);			//创建一个表长为m的空表
		~SqList();				//析构序表
		//void CreateList(int n); //创建一个具有n个元素的表
		void Insert(int i,T e); //在第i个位置插入e元素
		T Delete(int i);		//删除第i个位置上的元素
		T GetElem(int i);		//查询第i个位置上的元素
		int Locate(T e);		//元素定位
		void Clear();			//清空序表
		int Empty();			//序表判空
		int Full();				//序表判满
		void ListDisp();		//打印序表中的元素
		T Front(T e);			//查找元素前驱
		T Behind(T e);			//查找元素后继
		int GetLength();
};
template<class T>
int SqList<T>::GetLength(){
	return length;
}
template<class T>
SqList<T>::SqList(int m){
	elem = new T[m];				//为elem分配一个大小为m的空间
	if(!elem) throw"内存分配失败";
	length = 0;						//分配成功后将初始长度设为0
	listsize = m;					//设置最大容量
}
template<class T>
SqList<T>::~SqList(){
	//Clear();						//调用清空函数
	delete []elem;					//释放elem所占用的空间
	listsize = 0;					//表不存在
}
//创建序表
/*template<class T>
void SqList<T>::CreateList(int n){
	elem = new T[m];				//为elem分配一个大小为m的空间
	if(!elem) throw"内存分配失败";
	length = 0;						//分配成功后将初始长度设为0
	listsize = m;					//设置最大容量
}*/
//插入元素
template<class T>
void SqList<T>::Insert(int i,T e){
	if(length >= listsize) throw"序表已满 上溢";
	if(i < 1||i > length+1) throw"插入位置异常";
	for(int j=length;j>=i;j--)
		elem[j]=elem[j-1];			//将i位置及之后的元素依次往后移一位
	elem[i-1]=e;						//将e元素插入i位置
	length++;//表长+1
}
//删除元素
template<class T>
T SqList<T>::Delete(int i){
	T x=elem[i-1];						//标记删除元素
	if(i<1||i>length+1)throw"位置异常";	
	for(int j=i-1;j<=length-1;j++)		
		elem[j]=elem[j+1];				//将i位置及之后的元素依次往前移一位
	length--;							//表长-1
	return x;							//返回删除的x值

}
//查询元素
template<class T>
T SqList<T>::GetElem(int i){
	if(i<1||i>length+1)throw"位置异常";
	return elem[i-1];					//返回i位置上的值
}
//元素定位
template<class T>
int SqList<T>::Locate(T e){
	for(int j=0;j<=length;j++)
		if(e==elem[j])return j+1;		//查找elem【】中与e相等的数 找到则返回其位置
	return 0;							//没找到则返回0
}
//序表清空
template<class T>
void SqList<T>::Clear(){
	for(int j=0;j<=length;j++)
		elem[j]=NULL;					//遍历删除elem中的元素
	length=0;							//将序表长度重新置为0
}
//序表判空
template<class T>
int SqList<T>::Empty(){
	if(length==0)return 1;				//若序表中的元素为0个返回1 否则返回0
	return 0;
}
//序表判满
template<class T>
int SqList<T>::Full(){
	if(length==listsize-1)return 1;		//若序表中的元素个数length等于表的容量-1，返回1 否则返回0
	return 0;
}
//序表打印
template<class T>
void SqList<T>::ListDisp(){
	for(int j=0;j<=length-1;j++)
		cout<<"  "<<elem[j];
	
}
//查找前驱
template<class T>
T SqList<T>::Front(T e){
	for(int j=0;j<=length;j++)
		if(e==elem[j])return elem[j-1];		//查找elem【】中与e相等的数 找到则返回其前一个数
	return 0;
}
//查找后继
template<class T>
T SqList<T>::Behind(T e){
	for(int j=0;j<=length;j++)
		if(e==elem[j])return elem[j+1];		//查找elem【】中与e相等的数 找到则返回其后一个数
	return 0;
}
void Menu1(){
	cout<<endl;
	cout<<"1  插入      \t";cout<<"2  删除\n";
	
    cout<<"3  显示      \t";cout<<"4  按值找位\n";
    
    cout<<"5  按位找值  \t";cout<<"6  元素前驱\n";//?
    
    cout<<"7  元素后继  \t";cout<<"8  序表判空？\n";//?
    
    cout<<"9  序表判满？\t";cout<<"0  清空\n";
     
}
void Menu2(){
	SqList<int> L(100);
	int i,e;
	while(1){
	Menu1();
	int Choose;cin>>Choose;
	switch(Choose){
	case 1:{
		   cout<<"\t\t请输入插入的位置：";cin>>i;
		   cout<<"\n\t\t请输入插入的数据：";cin>>e;
		   	try{
				L.Insert(e,i);
				cout<<endl<<"插入成功！"<<endl;
				}
			catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"请输入删除的位置：";cin>>i;
		if(L.GetLength()>0)
		try{
			e=L.Delete(i);
			cout<<endl<<"删除成功！删除是数据是"<<e;
			}
		catch(const char *s){cout<<s<<endl;}
		else 
			cout<<"数据表中没有啦数据\n";
		}break;
	case 3:{
		i = L.GetLength();
		if(i>0){
		cout<<"表中的数值为：";
		L.ListDisp();
		}
		else 
			cout<<"\n表中没有数值";
		   }break;
	case 4:{
		cout<<"\n\t\t请输入查询的数据：";cin>>e;
		i=L.Locate(e);
		if(i==0)
			cout<<"\n表中没有该元素";
		else
			cout<<"\n表中该元素位置为:"<<i;
		   }break;
	case 5:{
		   cout<<"\n\t\t请输入查询的位置：";cin>>i;
		   try{
		   e=L.GetElem(i);
		   cout<<"\n表中该元素为:"<<e;
		   }
		   catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:{
		int x;
		cout<<"\n\t\t请输入查询的数据：";cin>>e;
		x=L.Front(e);
		if(i==0)
			cout<<"\n表中没有该元素";
		else
			cout<<"\n表中该元素的前驱为:"<<x;
		   }break;break;
	case 7:{
		int x;
		cout<<"\n\t\t请输入查询的数据：";cin>>e;
		x=L.Behind(e);
		if(i==0)
			cout<<"\n表中没有该元素";
		else
			cout<<"\n表中该元素位置为:"<<x;
		   }break;
	case 8:{
		   i=L.Empty();
		   if(i==1)cout<<"\n数据表为空";
		   else cout<<"\n数据表不为空";
		   }break;
	case 9:{
		   i=L.Full();
		   if(i==1)cout<<"\n数据表为满";
		   else cout<<"\n数据表不为满";
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

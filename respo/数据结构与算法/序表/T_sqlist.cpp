#include<iostream>
using namespace std;
template<class T>
class sqlist{
private:
	T *pa;
	int length;
	int listsize;
public:
	sqlist(int n){//构建线性顺序列表
	pa= new T[n];
	if(pa==NULL)throw"内存分配失败";
	listsize=n;
	length=0;
	}
	~sqlist(){//销毁列表
	delete []pa;
	}
	void Insert(T e,int i){//插入数据
	if(length==listsize)throw"表满 上溢";
	if(i<1||i>length+1)throw"插入异常";
	for(int j=length-1;j<i-1;j--)
		pa[j+1]=pa[j];
	pa[i-1]=e;length++;
	}
	T Delete(int i){//删除数据
		if(length==0)throw"位置异常";
		if(i<1||i>length)throw"输入异常";
		T e=pa[i-1];
		delete pa[i-1];
		for(int j=i;j<length;j++)
			pa[j-1]=p[j];
		length--;
		return e;
	}
	void Display(){//显示打印数据
	for(int i=0;i<length;i++)
		cout<<pa[i]<<endl;
	cout<<"length="<<length<<endl;
	}
	int DataFind(T e){//按值查找
	for(int j=0;j<length;j++)
		if(pa[j]==e)return j+1;
		couut<<"没找到该值"<<endl;
	}
	T LocaFind(int i){//按位置查找
	return p[i-1];
	couut<<"没找到该值"<<endl;
	}
	T Front(T e){//查找前驱
	for(int j=0;j<length;j++)
		if(pa[j]==e)return pa[j-1];
		couut<<"没找到该值"<<endl;
	}
	T Behind(T e){//查找后继
	for(int j=0;j<length;j++)
		if(pa[j]==e)return pa[j+1];
		couut<<"没找到该值"<<endl;
	}
	int Empty(){//判断表空
		if(length==0)cout<<"列表为空";
	}
	void Clear(){//清空列表
	for(int j=0;j<length;j++)
		delete pa[j];
	}
};
void Menu(){
	cout<<"1  插入\n";
	cout<<"2  删除\n";
    cout<<"3  显示\n";
    cout<<"4  按值查找\n";
    cout<<"5  按位置查找\n";
    cout<<"6  某元素的前驱\n";//?
    cout<<"7  某元素的后继\n";//?
    cout<<"8  判空表？\n";//?
    cout<<"9  清空？\n";//?
     cout<<"0  退出\n";
}
int main(){;
	sqlist<int> L(100);
	int i,e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:L.Insert(5,1);break;
	case 2:{
		int 
		L.Delete();}break;
	case 3:L.Display();break;
	case 4:L.DataFind();break;
	case 5:L.LocaFind();break;
	case 6:L.Front();break;
	case 7:L.Behind();break;
	case 8:L.Empty()break;
	case 9:L.Clear();break;
	case 0:break;
	default:break;

		}
	}
	return 0;
}
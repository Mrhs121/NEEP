#include<iostream>
using namespace std;
template<class T>
class sqlist{
private:
	T *pa;
	int length;
	int listsize;
public:
	sqlist(int n){//��������˳���б�
	pa= new T[n];
	if(pa==NULL)throw"�ڴ����ʧ��";
	listsize=n;
	length=0;
	}
	~sqlist(){//�����б�
	delete []pa;
	}
	void Insert(T e,int i){//��������
	if(length==listsize)throw"���� ����";
	if(i<1||i>length+1)throw"�����쳣";
	for(int j=length-1;j<i-1;j--)
		pa[j+1]=pa[j];
	pa[i-1]=e;length++;
	}
	T Delete(int i){//ɾ������
		if(length==0)throw"λ���쳣";
		if(i<1||i>length)throw"�����쳣";
		T e=pa[i-1];
		delete pa[i-1];
		for(int j=i;j<length;j++)
			pa[j-1]=p[j];
		length--;
		return e;
	}
	void Display(){//��ʾ��ӡ����
	for(int i=0;i<length;i++)
		cout<<pa[i]<<endl;
	cout<<"length="<<length<<endl;
	}
	int DataFind(T e){//��ֵ����
	for(int j=0;j<length;j++)
		if(pa[j]==e)return j+1;
		couut<<"û�ҵ���ֵ"<<endl;
	}
	T LocaFind(int i){//��λ�ò���
	return p[i-1];
	couut<<"û�ҵ���ֵ"<<endl;
	}
	T Front(T e){//����ǰ��
	for(int j=0;j<length;j++)
		if(pa[j]==e)return pa[j-1];
		couut<<"û�ҵ���ֵ"<<endl;
	}
	T Behind(T e){//���Һ��
	for(int j=0;j<length;j++)
		if(pa[j]==e)return pa[j+1];
		couut<<"û�ҵ���ֵ"<<endl;
	}
	int Empty(){//�жϱ��
		if(length==0)cout<<"�б�Ϊ��";
	}
	void Clear(){//����б�
	for(int j=0;j<length;j++)
		delete pa[j];
	}
};
void Menu(){
	cout<<"1  ����\n";
	cout<<"2  ɾ��\n";
    cout<<"3  ��ʾ\n";
    cout<<"4  ��ֵ����\n";
    cout<<"5  ��λ�ò���\n";
    cout<<"6  ĳԪ�ص�ǰ��\n";//?
    cout<<"7  ĳԪ�صĺ��\n";//?
    cout<<"8  �пձ�\n";//?
    cout<<"9  ��գ�\n";//?
     cout<<"0  �˳�\n";
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
#include<iostream>
using namespace std;
template<class T>
class SqList{
	private:
		T *elem;				
		int length;				//��¼��ǰԪ�ظ���
		int listsize;			//��ǵ�ǰ��������
	public:
		SqList(int m);			//����һ����Ϊm�Ŀձ�
		~SqList();				//�������
		//void CreateList(int n); //����һ������n��Ԫ�صı�
		void Insert(int i,T e); //�ڵ�i��λ�ò���eԪ��
		T Delete(int i);		//ɾ����i��λ���ϵ�Ԫ��
		T GetElem(int i);		//��ѯ��i��λ���ϵ�Ԫ��
		int Locate(T e);		//Ԫ�ض�λ
		void Clear();			//������
		int Empty();			//����п�
		int Full();				//�������
		void ListDisp();		//��ӡ����е�Ԫ��
		T Front(T e);			//����Ԫ��ǰ��
		T Behind(T e);			//����Ԫ�غ��
		int GetLength();
};
template<class T>
int SqList<T>::GetLength(){
	return length;
}
template<class T>
SqList<T>::SqList(int m){
	elem = new T[m];				//Ϊelem����һ����СΪm�Ŀռ�
	if(!elem) throw"�ڴ����ʧ��";
	length = 0;						//����ɹ��󽫳�ʼ������Ϊ0
	listsize = m;					//�����������
}
template<class T>
SqList<T>::~SqList(){
	//Clear();						//������պ���
	delete []elem;					//�ͷ�elem��ռ�õĿռ�
	listsize = 0;					//������
}
//�������
/*template<class T>
void SqList<T>::CreateList(int n){
	elem = new T[m];				//Ϊelem����һ����СΪm�Ŀռ�
	if(!elem) throw"�ڴ����ʧ��";
	length = 0;						//����ɹ��󽫳�ʼ������Ϊ0
	listsize = m;					//�����������
}*/
//����Ԫ��
template<class T>
void SqList<T>::Insert(int i,T e){
	if(length >= listsize) throw"������� ����";
	if(i < 1||i > length+1) throw"����λ���쳣";
	for(int j=length;j>=i;j--)
		elem[j]=elem[j-1];			//��iλ�ü�֮���Ԫ������������һλ
	elem[i-1]=e;						//��eԪ�ز���iλ��
	length++;//��+1
}
//ɾ��Ԫ��
template<class T>
T SqList<T>::Delete(int i){
	T x=elem[i-1];						//���ɾ��Ԫ��
	if(i<1||i>length+1)throw"λ���쳣";	
	for(int j=i-1;j<=length-1;j++)		
		elem[j]=elem[j+1];				//��iλ�ü�֮���Ԫ��������ǰ��һλ
	length--;							//��-1
	return x;							//����ɾ����xֵ

}
//��ѯԪ��
template<class T>
T SqList<T>::GetElem(int i){
	if(i<1||i>length+1)throw"λ���쳣";
	return elem[i-1];					//����iλ���ϵ�ֵ
}
//Ԫ�ض�λ
template<class T>
int SqList<T>::Locate(T e){
	for(int j=0;j<=length;j++)
		if(e==elem[j])return j+1;		//����elem��������e��ȵ��� �ҵ��򷵻���λ��
	return 0;							//û�ҵ��򷵻�0
}
//������
template<class T>
void SqList<T>::Clear(){
	for(int j=0;j<=length;j++)
		elem[j]=NULL;					//����ɾ��elem�е�Ԫ��
	length=0;							//�������������Ϊ0
}
//����п�
template<class T>
int SqList<T>::Empty(){
	if(length==0)return 1;				//������е�Ԫ��Ϊ0������1 ���򷵻�0
	return 0;
}
//�������
template<class T>
int SqList<T>::Full(){
	if(length==listsize-1)return 1;		//������е�Ԫ�ظ���length���ڱ������-1������1 ���򷵻�0
	return 0;
}
//����ӡ
template<class T>
void SqList<T>::ListDisp(){
	for(int j=0;j<=length-1;j++)
		cout<<"  "<<elem[j];
	
}
//����ǰ��
template<class T>
T SqList<T>::Front(T e){
	for(int j=0;j<=length;j++)
		if(e==elem[j])return elem[j-1];		//����elem��������e��ȵ��� �ҵ��򷵻���ǰһ����
	return 0;
}
//���Һ��
template<class T>
T SqList<T>::Behind(T e){
	for(int j=0;j<=length;j++)
		if(e==elem[j])return elem[j+1];		//����elem��������e��ȵ��� �ҵ��򷵻����һ����
	return 0;
}
void Menu1(){
	cout<<endl;
	cout<<"1  ����      \t";cout<<"2  ɾ��\n";
	
    cout<<"3  ��ʾ      \t";cout<<"4  ��ֵ��λ\n";
    
    cout<<"5  ��λ��ֵ  \t";cout<<"6  Ԫ��ǰ��\n";//?
    
    cout<<"7  Ԫ�غ��  \t";cout<<"8  ����пգ�\n";//?
    
    cout<<"9  ���������\t";cout<<"0  ���\n";
     
}
void Menu2(){
	SqList<int> L(100);
	int i,e;
	while(1){
	Menu1();
	int Choose;cin>>Choose;
	switch(Choose){
	case 1:{
		   cout<<"\t\t����������λ�ã�";cin>>i;
		   cout<<"\n\t\t�������������ݣ�";cin>>e;
		   	try{
				L.Insert(e,i);
				cout<<endl<<"����ɹ���"<<endl;
				}
			catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		cout<<"������ɾ����λ�ã�";cin>>i;
		if(L.GetLength()>0)
		try{
			e=L.Delete(i);
			cout<<endl<<"ɾ���ɹ���ɾ����������"<<e;
			}
		catch(const char *s){cout<<s<<endl;}
		else 
			cout<<"���ݱ���û��������\n";
		}break;
	case 3:{
		i = L.GetLength();
		if(i>0){
		cout<<"���е���ֵΪ��";
		L.ListDisp();
		}
		else 
			cout<<"\n����û����ֵ";
		   }break;
	case 4:{
		cout<<"\n\t\t�������ѯ�����ݣ�";cin>>e;
		i=L.Locate(e);
		if(i==0)
			cout<<"\n����û�и�Ԫ��";
		else
			cout<<"\n���и�Ԫ��λ��Ϊ:"<<i;
		   }break;
	case 5:{
		   cout<<"\n\t\t�������ѯ��λ�ã�";cin>>i;
		   try{
		   e=L.GetElem(i);
		   cout<<"\n���и�Ԫ��Ϊ:"<<e;
		   }
		   catch(const char *s){cout<<s<<endl;}
		   }break;
	case 6:{
		int x;
		cout<<"\n\t\t�������ѯ�����ݣ�";cin>>e;
		x=L.Front(e);
		if(i==0)
			cout<<"\n����û�и�Ԫ��";
		else
			cout<<"\n���и�Ԫ�ص�ǰ��Ϊ:"<<x;
		   }break;break;
	case 7:{
		int x;
		cout<<"\n\t\t�������ѯ�����ݣ�";cin>>e;
		x=L.Behind(e);
		if(i==0)
			cout<<"\n����û�и�Ԫ��";
		else
			cout<<"\n���и�Ԫ��λ��Ϊ:"<<x;
		   }break;
	case 8:{
		   i=L.Empty();
		   if(i==1)cout<<"\n���ݱ�Ϊ��";
		   else cout<<"\n���ݱ�Ϊ��";
		   }break;
	case 9:{
		   i=L.Full();
		   if(i==1)cout<<"\n���ݱ�Ϊ��";
		   else cout<<"\n���ݱ�Ϊ��";
		   }break;
	case 0:{
		   L.Clear();
		   cout<<"\n���ݱ������";
		   }break;
	default:break;

		}
	}
}
void main(){
	Menu2();
}

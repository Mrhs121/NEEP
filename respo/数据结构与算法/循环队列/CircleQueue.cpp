#include<iostream.h>
template<class T>
class CircleQueue{
    T  *elem;
	int front,rear;
	int QueueSize;
	int mark;
public:
    CircleQueue(int n){
    	elem=new T[n];
		front=rear=0;
       QueueSize=n;
	   mark=0;
	} 
    ~CircleQueue(){
    	delete []elem;		
	}

    void EnQueue(T x){
	    if((rear+1)%QueueSize==front)throw"��,buneng jindui\n";
		elem[rear]=  x;
		rear = (rear+1)%QueueSize;//�ؼ��Ĳ���
		mark=1;
	}

      T  DEQueue(){
	    if(rear==front)throw"��,buneng ��dui\n";
		T x=elem[front];
		front = (front+1)%QueueSize;//�ؼ��Ĳ���
		return x;
		mark=0;
	}

    T  GetHead(){
	    if(rear==front)throw"��,wuduishou yuansu\n";
		
		return elem[front];
	}
		
	int QueueEmpty(){
	  if(mark==0 && rear==front)return 1;else return 0;
	} 

	int QueueFull(){
		/*if((rear+1)%QueueSize==front)*/
		if(mark!=0 && rear==front)
		return 1;else return 0; 
	}

	void ClearQueue(){  
		rear=front=0;
	}

    void QueueDisp(){
		if(rear==front)
        {
           cout<<"��\n";return ;
        }
		cout<<"���ף�";
        
        
        //���
	    for(int i=front;
             i!=rear;)
		{
           cout<<elem[i]<<'\t';
           i=(i+1)%QueueSize;  
           //(rear-1+QueueSize)%QueueSize��βԪ�ص�λ��    	
        }
        
        
        cout<<"��β��";
	}

};

void Menu(){
	cout<<endl;
	cout<<"\t1  ���� ����\t\t4  ���� �п�\n";
	cout<<"\t2  ɾ�� ����\t\t5  ���� ����\n";
    cout<<"\t3  ��ʾ ����\t\t6  ���� ��ʾ\n";
    cout<<"\t7  ���� ���"<<endl;
    
}
int main(){
	CircleQueue<int> L(100);
	int e;
	while(1){
	Menu();
	int Choose;
	cin>>Choose;
	switch(Choose){
	case 1:{
		cout<<"�������������ݣ�";cin>>e;
		try{L.EnQueue(e);
		cout<<endl<<"����ɹ���"<<endl;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		try
		{e=L.DEQueue();
		cout<<endl<<"ɾ���ɹ���ɾ����������"<<e;
		}
		catch(const char *s){
			cout<<s<<endl;}
		}
		break;
	case 3:cout<<L.GetHead();break;

	case 4:try{L.QueueEmpty();}
		catch(const char *s){cout<<s<<endl;} break;
	case 5:try{L.QueueFull();}
		catch(const char *s){cout<<s<<endl;} break;
	case 6:L.QueueDisp();break;
	case 7:L.ClearQueue();break;
	default:break;
		}
	}
	return 0;
}
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
	    if((rear+1)%QueueSize==front)throw"满,buneng jindui\n";
		elem[rear]=  x;
		rear = (rear+1)%QueueSize;//关键的操作
		mark=1;
	}

      T  DEQueue(){
	    if(rear==front)throw"空,buneng 出dui\n";
		T x=elem[front];
		front = (front+1)%QueueSize;//关键的操作
		return x;
		mark=0;
	}

    T  GetHead(){
	    if(rear==front)throw"空,wuduishou yuansu\n";
		
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
           cout<<"空\n";return ;
        }
		cout<<"队首：";
        
        
        //查错
	    for(int i=front;
             i!=rear;)
		{
           cout<<elem[i]<<'\t';
           i=(i+1)%QueueSize;  
           //(rear-1+QueueSize)%QueueSize队尾元素的位置    	
        }
        
        
        cout<<"队尾：";
	}

};

void Menu(){
	cout<<endl;
	cout<<"\t1  插入 数据\t\t4  队列 判空\n";
	cout<<"\t2  删除 数据\t\t5  队列 判满\n";
    cout<<"\t3  显示 队首\t\t6  队列 显示\n";
    cout<<"\t7  队列 清空"<<endl;
    
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
		cout<<"请输入插入的数据：";cin>>e;
		try{L.EnQueue(e);
		cout<<endl<<"插入成功！"<<endl;}
		catch(const char *s){cout<<endl<<s<<endl;}
		   }break;
	case 2:{
		try
		{e=L.DEQueue();
		cout<<endl<<"删除成功！删除是数据是"<<e;
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
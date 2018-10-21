#include <iostream>
using namespace std;

#include <conio.h>
#include <fstream.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define   UP     72   
#define   DOWN   80   
#define   LEFT   75   
#define   RIGHT  77

int j; //ʳ����ִ���
int t_x;  //��¼��β
int t_y;  //��¼��β
int n;    //����
int s_speed;  //�ٶ�
int best;     //��ǿ
int two_best;          //�ڶ�������
int three_best;        //����������
char name[20];         //��һ��
char two_name[20];     //�ڶ�������
char three_name[20];   //����������

int main();

void gotoxy(int x,int y)
{
	CONSOLE_SCREEN_BUFFER_INFO   csbilnfo;
	HANDLE  hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbilnfo);	  
	csbilnfo.dwCursorPosition.X = x;
	csbilnfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut,csbilnfo.dwCursorPosition);
}

void print()   //�߿�
{
	int star_x = 5;
	int star_y = 5;
	int lenth = 20;
	int width = 20;
	int i;
	gotoxy(star_x,star_y);           cout<<"��"<<endl;   //(5,5)
	gotoxy(star_x+2*width,star_y); cout<<"��"<<endl;   //(45,5)
	gotoxy(star_x,star_y+lenth); cout<<"��"<<endl;     //(5,25)
	gotoxy(star_x+2*width,star_y+lenth); cout<<"��"<<endl;  //(45,25)
	gotoxy(star_x+2*width+8,star_y+1);  cout<<"̰����С��Ϸ"<<endl;
	for(i=2;i<2*width;i+=2)
	{
		gotoxy(star_x+i,star_y);
		cout<<"��"<<endl;
		gotoxy(star_x+i,star_y+lenth);
		cout<<"��"<<endl;
	}
	for(i=1;i<lenth;i++)
	{
		gotoxy(star_x,star_y+i);
		cout<<"��"<<endl;
		gotoxy(star_x+2*width,star_y+i);
		cout<<"��"<<endl;
	}
	cout<<endl;
}

struct snake   
{
	int x[100];		//С�ߵĺ�����
	int y[100];		//С�ߵ�������
	int length;		//С�ߵĳ���
};

void star_snake(struct snake *s_snake)  //��ʼ��һ��С����
{
	int star_x = 5;
	int star_y = 5;
	int lenth = 20;
	int width = 20;
	int i;
	s_snake->x[0]=star_x+2;
	s_snake->y[0]=star_y+lenth/2;
	s_snake->length=4;
	
	for(i=1;i<s_snake->length;i++)
	{
		s_snake->x[i]=s_snake->x[i-1]+2;
		s_snake->y[i]=s_snake->y[i-1];
		
	}
	
}

void print_snake(struct snake*s_snake)  //����һ��С��
{
    int i;
	for(i=0;i<s_snake->length;i++)
    {
		gotoxy(s_snake->x[i],s_snake->y[i]);
		if(i==0)
		{
			cout<<"��"<<endl;  //β
		}
		else if(i==s_snake->length-1)
		{
			cout<<"��"<<endl;   //ͷ
		}
		else
		{
			cout<<"��"<<endl;   //��
		}
		
	} cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

void move_snake(struct snake *s_snake)  //�ƶ�
{
	int i;
	gotoxy(s_snake->x[0],s_snake->y[0]);		
	cout<<"  "<<endl;
	for(i=1;i<s_snake->length;i++)
	{
		s_snake->x[i-1]=s_snake->x[i];
		s_snake->y[i-1]=s_snake->y[i];
	}
}

struct food
{
	int food_x;   //ʳ�������
	int food_y;   //ʳ��������
};

void food(struct snake *s_snake,struct food *f_food)   //����ʳ��  
{
	srand(time(NULL));
	while(1)
	{
		f_food->food_x = 7+2*(rand() % 19 + 0);
		f_food->food_y = 6+rand() % 19+ 0; 
		for(int i=0;i<s_snake->length;i++)
		{
			if(f_food->food_x==s_snake->x[i] && f_food->food_y==s_snake->y[i])
			{
				break;
			}
		}
		if(i==s_snake->length)
		{
			gotoxy(f_food->food_x,f_food->food_y);
			cout<<"��"<<endl;
			break;
		}
	}
}

int dide(struct snake *s_snake)   //����//�����Լ�
{
	int a=0,b=1;
	for(int i=0;i<s_snake->length-1;i++)
	{
		if(s_snake->x[s_snake->length-1]==s_snake->x[i] && s_snake->y[s_snake->length-1]==s_snake->y[i])
			return b;
	}
	if(i==s_snake->length-1)
	{
		return a;
	}
	
}

int if_food(struct snake *s_snake,struct food *f_food)  //�ж��Ƿ�Ե�ʳ
{
	int a = 1; int b = 0; 
	if(s_snake->x[s_snake->length-1]==f_food->food_x && s_snake->y[s_snake->length-1]==f_food->food_y)
	{  
		j++;    
		return a;
	}
	else {  return b;}
}

void add_snake(struct snake *s_snake)  //�ӳ��ߵĳ���
{
	s_snake->length++;
	int head_x = s_snake->x[s_snake->length-1];  //��¼ͷ��λ��
	int head_y = s_snake->y[s_snake->length-1];  //
	for(int i=s_snake->length--;i>=0;i--)
	{
		s_snake->x[i] = s_snake->x[i-1];
		s_snake->y[i] = s_snake->y[i-1];
	}  
	s_snake->x[0]=t_x;
	s_snake->y[0]=t_y;
}

void speed()  //��ʳ�ı��ٶȺ͵÷�
{
	s_speed = 300 - 10*j;   
	if(s_speed <= 60)
	{
		s_speed = 60;
	}
	n = 100*j;
	int star_x = 5;
	int star_y = 5;
	int lenth = 20;
	int width = 20;
	gotoxy(star_x+2*width+8,star_y+3);  cout<<"��ǰ�÷�:"<<n<<endl;
	gotoxy(star_x+2*width+8,star_y+5);  cout<<"�ٶ�:"<<s_speed<<endl;
	gotoxy(star_x+2*width+8,star_y+7);  cout<<"����:����"<<endl;
	gotoxy(star_x+2*width+8,star_y+9);  cout<<"best:"<<best<<endl;
	gotoxy(star_x+2*width+8,star_y+11);  cout<<"��һ��:"<<name<<endl;
	gotoxy(star_x+2*width+8,star_y+13);  cout<<"�ڶ���:����"<<" ���Է�"<<endl;
	gotoxy(star_x+2*width+8,star_y+15);  cout<<"������:����"<<" ���Է�"<<endl;
}
void save()
{
	ofstream in("best.dat");  
	in<<n<<" "<<name;
	in.close();
	
}
//void paiwei(int score)   //�ɼ���λ����
//{

//}
void play()   //��ʼ��Ϸ
{
	char ch = UP;
	struct snake s,*ss_snake=&s;
	struct food f,*ff_food=&f;
	star_snake(ss_snake);
	print_snake(ss_snake);
	food(ss_snake,ff_food);
	while(1)
	{
		print();
		if(kbhit())
		{ 
			getch();
			ch=getch();
		}		
		
		switch(ch)
		{
		case UP:	
			if(ss_snake->y[ss_snake->length-2]==ss_snake->y[ss_snake->length-1]-1)
			{
				ch = DOWN;         //��ֹ�������ߵ�ʱ���ϼ�
				break;
			}
			else
			{
				t_x=ss_snake->x[0]; t_y=ss_snake->y[0];
				move_snake(ss_snake);
				ss_snake->y[ss_snake->length-1]-=1;			   			   
				if(ss_snake->y[ss_snake->length-1]==5)
				{
					ss_snake->y[ss_snake->length-1] = 24;
				}			   			   
				break;     
			}         
		case DOWN:					 				      
			if(ss_snake->y[ss_snake->length-2]==ss_snake->y[ss_snake->length-1]+1)
			{
				ch = UP;
				break;
			}
			else
			{  
				t_x=ss_snake->x[0]; t_y=ss_snake->y[0];
				move_snake(ss_snake);
				ss_snake->y[ss_snake->length-1]+=1;
				if(ss_snake->y[ss_snake->length-1] == 25)
				{
					ss_snake->y[ss_snake->length-1] = 6;
				}
				break;
			}
		case RIGHT:
			if(ss_snake->x[ss_snake->length-2]==ss_snake->x[ss_snake->length-1]+2)
			{
				ch = LEFT;
				break;
			}
			else
			{
				t_x=ss_snake->x[0]; t_y=ss_snake->y[0];
				move_snake(ss_snake);
				ss_snake->x[ss_snake->length-1]+=2;
				if(ss_snake->x[ss_snake->length-1] == 45)
				{
					ss_snake->x[ss_snake->length-1] = 7;
				}
				break;
			}		   
		case LEFT:					 				      
			if(ss_snake->x[ss_snake->length-2]==ss_snake->x[ss_snake->length-1]-2)
			{
				ch = RIGHT;
				break;
			}
			else
			{
				t_x=ss_snake->x[0]; t_y=ss_snake->y[0];
				move_snake(ss_snake);
				ss_snake->x[ss_snake->length-1]-=2;
				if(ss_snake->x[ss_snake->length-1] == 5)
				{
					ss_snake->x[ss_snake->length-1] = 43;
				}		   
				break;  	
			}
		default:
			break;
			
		}
		if(dide(ss_snake))  //�ж�����
		{ 
			gotoxy(15,15);
			cout<<"С������,��Ϸ����!!!"<<endl;
/////////////////////////////////////////////////////////////////////////////////// 
			if(n>best)
			{
				gotoxy(15,16);
				cout<<"�����û���"<<endl;
				cin>>name;
				save();
				char v;
				gotoxy(15,17);
				cout<<"��y������Ϸ��n�˳���Ϸ\n";
				cin>>v;
				if(v == 'y'){
					n = 0;
					j = 0;
					main();}                                               //�жϳɼ�
				else
					exit(1);
			}
			else
			{
				char k;
				gotoxy(15,17);
				cout<<"��y������Ϸ��n�˳���Ϸ\n";
				cin>>k;
				if(k == 'y'){
					j = 0;
					n = 0;
					main();}
				else
					exit(1);
			}
		}  
////////////////////////////////////////////////////////////////////////////////////////////////////////		
		if(if_food(ss_snake,ff_food))     //�ж��Ƿ��ʳ
		{
			PlaySound(TEXT("m1.wav"), NULL, SND_FILENAME | SND_ASYNC );
			add_snake(ss_snake);
			ss_snake->length++;           			   
			food(ss_snake,ff_food);			   
			
		}        
		print_snake(ss_snake); 
		speed();
		Sleep(s_speed);
   }
}

int main()
{
	n = 0;
	int b_best = 0;
	char n_name[20] = "����";
	system("color 0a");
	system("title ̰����_����:����");
	system("mode con cols=80 lines=35");
	
	ifstream on("best.dat");
	if(on==NULL)
	{
		best = 0;
	}
	else
	{
		while(!on.eof())              
		{ 
			on>>b_best>>n_name;
			best = b_best;
			strcpy(name,n_name);		
		}      
        on.close();
	}
	
	print();
	play();
	return 0;
}

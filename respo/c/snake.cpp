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

int j; //食物出现次数
int t_x;  //记录蛇尾
int t_y;  //记录蛇尾
int n;    //分数
int s_speed;  //速度
int best;     //最强
int two_best;          //第二名分数
int three_best;        //第三名分数
char name[20];         //第一名
char two_name[20];     //第二名名字
char three_name[20];   //第三名名字

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

void print()   //边框
{
	int star_x = 5;
	int star_y = 5;
	int lenth = 20;
	int width = 20;
	int i;
	gotoxy(star_x,star_y);           cout<<"┌"<<endl;   //(5,5)
	gotoxy(star_x+2*width,star_y); cout<<"┐"<<endl;   //(45,5)
	gotoxy(star_x,star_y+lenth); cout<<"└"<<endl;     //(5,25)
	gotoxy(star_x+2*width,star_y+lenth); cout<<"┘"<<endl;  //(45,25)
	gotoxy(star_x+2*width+8,star_y+1);  cout<<"贪吃蛇小游戏"<<endl;
	for(i=2;i<2*width;i+=2)
	{
		gotoxy(star_x+i,star_y);
		cout<<"─"<<endl;
		gotoxy(star_x+i,star_y+lenth);
		cout<<"─"<<endl;
	}
	for(i=1;i<lenth;i++)
	{
		gotoxy(star_x,star_y+i);
		cout<<"│"<<endl;
		gotoxy(star_x+2*width,star_y+i);
		cout<<"│"<<endl;
	}
	cout<<endl;
}

struct snake   
{
	int x[100];		//小蛇的横坐标
	int y[100];		//小蛇的竖坐标
	int length;		//小蛇的长度
};

void star_snake(struct snake *s_snake)  //初始化一条小蛇仔
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

void print_snake(struct snake*s_snake)  //画出一条小蛇
{
    int i;
	for(i=0;i<s_snake->length;i++)
    {
		gotoxy(s_snake->x[i],s_snake->y[i]);
		if(i==0)
		{
			cout<<"■"<<endl;  //尾
		}
		else if(i==s_snake->length-1)
		{
			cout<<"◆"<<endl;   //头
		}
		else
		{
			cout<<"○"<<endl;   //身
		}
		
	} cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

void move_snake(struct snake *s_snake)  //移动
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
	int food_x;   //食物横坐标
	int food_y;   //食物竖坐标
};

void food(struct snake *s_snake,struct food *f_food)   //产生食物  
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
			cout<<"☆"<<endl;
			break;
		}
	}
}

int dide(struct snake *s_snake)   //死亡//碰到自己
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

int if_food(struct snake *s_snake,struct food *f_food)  //判断是否吃到食
{
	int a = 1; int b = 0; 
	if(s_snake->x[s_snake->length-1]==f_food->food_x && s_snake->y[s_snake->length-1]==f_food->food_y)
	{  
		j++;    
		return a;
	}
	else {  return b;}
}

void add_snake(struct snake *s_snake)  //加长蛇的长度
{
	s_snake->length++;
	int head_x = s_snake->x[s_snake->length-1];  //记录头的位置
	int head_y = s_snake->y[s_snake->length-1];  //
	for(int i=s_snake->length--;i>=0;i--)
	{
		s_snake->x[i] = s_snake->x[i-1];
		s_snake->y[i] = s_snake->y[i-1];
	}  
	s_snake->x[0]=t_x;
	s_snake->y[0]=t_y;
}

void speed()  //吃食改变速度和得分
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
	gotoxy(star_x+2*width+8,star_y+3);  cout<<"当前得分:"<<n<<endl;
	gotoxy(star_x+2*width+8,star_y+5);  cout<<"速度:"<<s_speed<<endl;
	gotoxy(star_x+2*width+8,star_y+7);  cout<<"作者:黄晟"<<endl;
	gotoxy(star_x+2*width+8,star_y+9);  cout<<"best:"<<best<<endl;
	gotoxy(star_x+2*width+8,star_y+11);  cout<<"第一名:"<<name<<endl;
	gotoxy(star_x+2*width+8,star_y+13);  cout<<"第二名:测试"<<" 测试分"<<endl;
	gotoxy(star_x+2*width+8,star_y+15);  cout<<"第三名:测试"<<" 测试分"<<endl;
}
void save()
{
	ofstream in("best.dat");  
	in<<n<<" "<<name;
	in.close();
	
}
//void paiwei(int score)   //成绩排位函数
//{

//}
void play()   //开始游戏
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
				ch = DOWN;         //防止蛇向下走的时候按上键
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
		if(dide(ss_snake))  //判断死亡
		{ 
			gotoxy(15,15);
			cout<<"小蛇死了,游戏结束!!!"<<endl;
/////////////////////////////////////////////////////////////////////////////////// 
			if(n>best)
			{
				gotoxy(15,16);
				cout<<"输入用户名"<<endl;
				cin>>name;
				save();
				char v;
				gotoxy(15,17);
				cout<<"按y继续游戏，n退出游戏\n";
				cin>>v;
				if(v == 'y'){
					n = 0;
					j = 0;
					main();}                                               //判断成绩
				else
					exit(1);
			}
			else
			{
				char k;
				gotoxy(15,17);
				cout<<"按y继续游戏，n退出游戏\n";
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
		if(if_food(ss_snake,ff_food))     //判断是否吃食
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
	char n_name[20] = "无人";
	system("color 0a");
	system("title 贪吃蛇_作者:黄晟");
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

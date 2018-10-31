#include <stdio.h>
#include <stdlib.h>

unsigned char* i2ba(int n, unsigned char *s)
{
    

    // 相当于取下多少位出来 0xff 为屏蔽码，表示八位二进制的 1111 1111
    s[0] = n % 0xFF;
    s[1] = (n >> 8) & 0xFF;

    s[2] = (n >> 16) & 0xFF;
    s[3] = (n >> 24) & 0xFF;
	return s; 
}


int mark[100][100];
//完美解决方案
int find(int **a,int h,int w,int i,int j){

	if (i<0 || i>=h || j<0 || j>=w ||  a[i][j]==0)
	{
		return 0;
	}
	if(mark[i][j] != -1){
		return 0;
	}
	mark[i][j] = 1;
	printf("check : (%d,%d)\n",i,j);
	// find rigth
	// find top
	// find down
	// find left
	return find(a,h,w,i,j+1)+find(a,h,w,i-1,j)+find(a,h,w,i,j-1)+find(a,h,w,i+1,j)+1;
}

int maxBlock(int **a,int h,int w){
	int max = -1;
	int i=0,j=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(a[i][j]==1 && mark[i][j]==-1){
				int current_max = find(a,h,w,i,j);
				printf("current_max = %d\n",current_max );
				max = (max<current_max?current_max:max);
			}
		}
	}
	return max;
}


int checkBit(int x,int N)
{
	// 就是暴力呗
    int i;
    //printf("N = %d\n",N);
    for(i=2;i<N;i++)
    {
    	// 16进制07 111 05 101 与1进行位与&运算，值保持不变； 与0进行位与&运算，值清0；
        if((x&07)==05){
        	//printf("%d\n",x);
            return 1;
        }
        // 每次移动一位 暴力解法，尝试所有的可能
        x>>=1;        
    }
    return 0;
}

int test101()
{
  
	int x,N,counter=0;
    scanf("%d",&N);

    int upbd=~(~0<<N);
    // 算出一共有多少种组合，暴力遍历
    for(x=0;x<=upbd;x++)
    {
        if(checkBit(x,N)==0){
            counter++;
        }
        //printf("x = %d counter = %d\n",x,counter);
    }
    //printf("%d\n",counter);
    return 0;
}
void  testMaxBlock()
{
    int data[5][10] = {
    0,0,1,0,0,0,0,0,1,1,
    0,1,1,0,0,1,1,1,1,1,
    0,1,0,0,0,1,0,0,0,0,
    0,1,1,1,1,1,1,0,1,1,
    1,1,1,1,1,1,1,1,0,0};
    int **p;
    p  = (int**)malloc(sizeof(int *)*5);
    int i=0,j=0;
    for( i=0;i<10;i++ ) //为每行分配数组
        p[i]=(int *)malloc(10*sizeof(int) );
    
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            mark[i][j] = -1;
            p[i][j] = data[i][j];
        }
    }
    int max = maxBlock(p,5,10);
}
int main()
{

	test101();
	// unsigned char s[4];
	// i2ba(200,s);
	// printf("%d %d %d %d\n",s[0],s[1],s[2],s[3]);
	return 1;
}

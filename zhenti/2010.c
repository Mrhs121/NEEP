#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./myhead.h"
static void print(char data[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%c ",data[i]);
	}
	printf("\n");
}

// 类比2017第三大题 将十进制转为十六进制输出
// 采取递归的方法
static void HtoD(int x){
    if(x==0)
        return;
    int Divisor = x/16;
    int mod = x%16;
    HtoD(Divisor);    
    if(mod>=10)// 如果余数大于10则转换为A-F输出
        printf("%c",'A'+(mod-10));
    else 
        printf("%d",mod);
} // 完美解决方案

char * ui2hex(unsigned n,char *s){
	int d;
	int mod;
	int i=0;
	char temp;
	// 常规的计算
	do{
		d = n/16;
		mod = n%16;
		n /= 16;
		if(mod>=10)
			s[i++] = 'A'+(mod-10);
		else
			s[i++] = '0' + mod;
	}while(d!=0);
	s[i] = '\0';
	int length = i-1;
	// 最后将字符串反转即可
	for(i=0;i<=length/2;i++){
		temp = s[i];
		s[i] = s[length-i];
		s[length-i] = temp;
	}
	printf("%s\n", s);
	return s;
}


void putAll(int m,int n,char * data){

}

int strins(char  s1[],int i,char s2[]){
	int m,n,k;
	m = strlen(s1);
	n = strlen(s2);
	// s1 move to back
	for(k=m;k>=i;k--)
		s1[n+k] = s1[k];
	for(k=0;k<n;k++)
		s1[i+k] = s2[k];
	print(s1,m+n);
	return 1;
}
// n:元素个数 m:几个字符组成
void combine(char data[],int left,int n,int m,char com[20]){
	if(m==0){
		printf("\n");
		return;
	}
	int i = 0;

	for(i=left;i<n;i++){
		printf("%d ",i);
		combine(data,left+1,n,m-1,com);
	}
}
// n:元素个数 m:几个字符组成
// 采用位运算，绝了
void combine2(char data[],int n,int m){
	
}


void printMatrix(int ** p,int n){
	int i = 0,j=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", *((int *)p+i*n+j) );
		}
		printf("\n");
	}
}


// 矩阵的转置
// 注意：如果直接传的是强制转换后的二维数组，则需要用过指针的运算寻址，不能通过下表寻址
void matrixInvert(int ** a,int n){
	int i = 0,j=0;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
				int temp = *((int *)a+i*n+j) ;
				*((int *)a+i*n+j) = *((int *)a+j*n+i);
				*((int *)a+j*n+i) = temp;		
		}
	}
}


void main_102()
{
 int n = 4 ,m = 3;
 char a[] = { 'a', 'b' ,'c','d','e','f','g','h','i','j' };
 //char a[] = { "abcdefgh" };
 char buff[20];
 int count;
 int c =0;
 printf("all :%d\n",1<<n);
 // 4个 1111 10个1111111111
 for (int i = 0; i < (1 << n); i++)
 {
	c++;
	count = 0;
	// 重置缓存数组
    memset(buff, 0, 20);
	// 取出每一位，然后统计1的个数
	for (int bit = 1, pos = 0; bit < (1 << n); bit = (bit << 1), pos ++)
	{
		// bit : 0000001 0000010  00000100，一位一位的进行比较，i即为所有可能的情况
		if ((i & bit) == bit)
		{
			buff[count] = a[pos];
			count ++; 
		}
	}
	if (count == m)
		printf("%s\r\n", buff);
 }
 	printf("c = %d \n", c);
}//缺点 ： 时间复杂度较高
int test2010()
{
	// char a[] = { 'a', 'b' ,'c','d','e','f','g','h','i','j' };
	// char com[20];
	// combine(a,0,4,3,com);
	main_102();
	// int data[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	// // int **p;
 // //    p  = (int**)malloc(sizeof(int *)*4);
 // //    int i=0,j=0;
 // //    for( i=0;i<4;i++ )
 // //        p[i]=(int *)malloc(4*sizeof(int) );
    
 // //    for(i=0;i<4;i++){
	// //     for(j=0;j<4;j++){
	// //         p[i][j] = data[i][j];
	// //     }
 // //    }
 //    printMatrix((int **)data,4);
 //    matrixInvert((int **)data,4);
 //    printMatrix((int **)data,4);

	// char a = 9+'0';
	// printf("%c\n", a);
	// char * s;
	// s = ui2hex(671,s); 
	// printf("hex = %s\n",s);
	// char a[20] = {'a','b','e'};
	// char b[20] = {'c','d'}; 
	// strins(a,2,b);
	return 1;
}

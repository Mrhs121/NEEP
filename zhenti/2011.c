#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../datastruct/tools/mytools.h"
unsigned char* i2ba(int n, unsigned char *s)
{
    

    // 相当于取下多少位出来 0xff 为屏蔽码，表示八位二进制的 00000000 ~~~~~~ 1111 1111
    s[0] = n & 0xFF;
    s[1] = (n >> 8) & 0xFF;

    s[2] = (n >> 16) & 0xFF;
    s[3] = (n >> 24) & 0xFF;
	return s; 
}


int mark[100][100];
//完美解决方案
int find(int **a,int h,int w,int i,int j){

	if (i<0 || i>=h || j<0 || j>=w ||  *((int *)a+i*w+j)==0)
	{
		return 0;
	}
	if(mark[i][j] != -1){
		return 0;
	}
	mark[i][j] = 1;
	//printf("check : (%d,%d)\n",i,j);
	// find rigth
	// find top
	// find down
	// find left
	return find(a,h,w,i,j+1)+find(a,h,w,i-1,j)+find(a,h,w,i,j-1)+find(a,h,w,i+1,j)+1;
}
// 
int maxBlock(int **a,int h,int w){
	int max = -1;
	int i=0,j=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(  *((int *)a+i*w+j)==1 && mark[i][j]==-1){
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

// 计算不含101串的个数
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
    0,0,1,1,1,1,0,1,1,1,
    0,0,1,1,1,1,0,1,1,1};
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

    int max = maxBlock((int **)data,5,10);
}

float print(int arr[],int n){
    int i=0;
    float sum = 0;
    for(i=0;i<n;i++){
       printf("%d ",arr[i]);
        sum += arr[i];
    }
    printf("\n");
    return sum;
}
// 例如表达式 100a+10=4a-2+123-22a char express[] = "100a+10=4a-2+123-22a";
// 思路：将每个参数全部提取出来100a 10 -4a 2 -123 22a
// 然后将纯数字放入一个数组中
// 变量放在另外一个数组中
double equation(char express[]){
    int rightOrleft = 1;
    int next = 1;
    int i=0,m=0,n=0;
    char c = express[i];
    int var[10]; // 存放变量前面的系数
    int para[10]; // 存放实数
    int top = 0;
    char temp[10];
    if(express[0]=='-'){
        next = -1;
        c = express[++i];
    }
    、
    while (c!='\0') {
        if( (c<='9' && c>='0') || (c<='z' && c>='a')){
            //将用于计算的变量或者纯数字缓存起来
            temp[top++] = c;
            temp[top] = '\0';//用于后面的字符串转数字
        } else {
            // 处理加减符号
            top--; //除去末尾的'\0'
            if(temp[top]<='z' && temp[top]>='a'){
                //如果缓存的是变量 1a 3a 100a -1a 末尾必定是字母
                var[m++] = rightOrleft*next*(temp[0]>='a'?1:atoi(temp));
            } else {
                //如果缓存的是纯数字
                para[n++] = rightOrleft*next*(atoi(temp));
            }
            // 对下一个对象正负的判断
            if(c=='-'){
                next = -1;
            } else if(c == '+'){
                next = 1;
            }
            // 缓存清零
            top = 0;
                   if(c=='='){
            next = 1;
            rightOrleft = -1;
            }
        }
 
        c = express[++i];
    }
    top--;// 除去最后一个'\0'
    // 处理最后一个参数或者变量
    if(temp[top]<='z' && temp[top]>='a')
        var[m++] = rightOrleft*next*(atoi(temp));
    else
        para[n++] = rightOrleft*next*(atoi(temp));
    return -print(para, n)/print(var, m);
}

int cmp_int(const void* a, const void* b)
{
    //Applicationssert(a != NULL && b != NULL);
    const int* lhs = (const int*)a;
    const int* rhs = (const int*)b;
    if (*lhs < *rhs) {
        return -1;
    } else if (*lhs == *rhs) {
        return 0;
    } else {
        return 1;
    }
}
void *search(void* key,void* base,size_t num,size_t width,
            int(*compare)(const void* elem1, const void* elem2))
{
    size_t start = 0, end = num;
    int result;

    while(start < end)
    {
        size_t mid = start + (end - start) / 2;
        result = compare(key, base + mid * width);
        if(result < 0)
            end = mid;
        else if(result > 0)
            start = mid + 1;
        else
            return (void *)base + mid * width;
    }
    return NULL;
}

void del(char str[],char ch,int n){
    int i = 0;
    int m = 0;
    for(i=0;i<n;i++){
        if(str[i]!=ch)
            str[m++] = str[i];
    }
    printCharArr(str,m);
} // 有效的避免了大量的移动，一趟循环就可以完成,时间复杂度O(n)

void print101(int n){
    //思路：使用二进制101作为屏蔽码与目标码进行比较，目标码每次移动一位，循环比较
}

int numSum = 0, xSum = 0;
int isRight = 0;
void eval(char *numBuff, int isX)
{
 int num = atoi(numBuff);
if (isX) {
  if (num == 0)
   num = 1;
  if (isRight > 0)
   xSum -= num;
  else
   xSum += num;
} else {
  if (isRight > 0)
   numSum += num;
  else
   numSum -= num;
}
 memset(numBuff, 0, 80);
}
void main_112()
{
    char exp[80] = { "a-5+1=2+2a" }; // char exp[80] = { "3y=3" }; //char exp[80] = { "3y=1+y" };
    char xVarName;
    char numBuff[80] = { 0 };
    for (unsigned int i = 0; i < strlen(exp); i++)
    {
        if ((exp[i] >= '0' && exp[i] <= '9') || (exp[i] == '+') || (exp[i] == '-')) {
            if ((exp[i] == '+') || (exp[i] == '-'))
                eval(numBuff, 0);
            strncat(numBuff, &exp[i], 1);
        }
        else if (exp[i] == '=')
        {
            eval(numBuff, 0);
            isRight = 1;
        } else {
            xVarName = exp[i];
            eval(numBuff, 1);
        }
    }
    eval(numBuff, 0);
    printf("%s\r\n", exp);
    printf("%c=%.3f\r\n", xVarName, (float)numSum / (float)xSum);
    printf("%d : %d", numSum, xSum);

}


int main()
{

    main_112();
    char express[] = "a-5+1=2+2a";
    printf("\n");
    printf("%s\na = %.3f\n",express,equation(express));
    //printf("%d",0&&0);
    //testMaxBlock();
    // char str[] = {'c','c','b','c','c','d','e'};
    // del(str,'c',7);
	// test101();
	// //char express[] = "-5a+10=4a-2+123-22a+22";
	// char express[] = "12a-5+1=2+2a";
 //    printf("%s\na = %.5f\n",express,equation(express));
	// unsigned char s[4];
 //    int aa;
 //    scanf("%d",&aa);
	// i2ba(aa,s);
	// printf("%d %d %d %d\n",s[0],s[1],s[2],s[3]);
 //    unsigned char s2[4];
 //    *((int *)s2) = aa;
  
 //    printf("%s %c %d %d %d\n",s2,s2[0],s2[1],s2[2],s2[3]);
 //    unsigned char b = 123;
 //    printf("b = %c\n",b);
	return 1;
}

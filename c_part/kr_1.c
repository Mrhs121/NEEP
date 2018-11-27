#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../datastruct/tools/mytools.h"
#define MAXLINE 1000
#define MAXNUM 200


typedef struct  Score{
    int num;
    char name[20];
    int score;
}Stu[200];

void printString(char str[]);
void getLine(char s[],int lim);


void reverse(char s[],int size)
{
    printf("size :%d\n",size);
    printString(s);
}

/*
void printString(char str[]){
    int i=0;
    char c = str[i];
    while(c!='\0'){
        printf("%c",c);
        c = str[++i];
    }
    printf("\n");
    
}
*/

void   itoa   (   unsigned   long   val,   char   *buf,   unsigned   radix    )   
{   
                char   *p;                                 /*   pointer   to   traverse   string   */   
                char   *firstdig;                   /*   pointer   to   first   digit   */   
                char   temp;                             /*   temp   char   */   
                unsigned   digval;                 /*   value   of   digit   */   

    p   =   buf;   
                firstdig   =   p;                       /*   save   pointer   to   first   digit   */   

    do   {   
        digval   =   (unsigned)   (val   %   radix);   
                                        val   /=   radix;               /*   get   next   digit   */   

                                        /*   convert   to   ascii   and   store   */   
        if   (digval   >   9)   
                                                *p++   =   (char   )   (digval   -   10   +   'a');     /*   a   letter   */   
            else   
                                                *p++   =   (char   )   (digval   +   '0');               /*   a   digit   */   
        }   while   (val   >   0);   

                /*   We   now   have   the   digit   of   the   number   in   the   buffer,   but   in   reverse   
                 *                         order.     Thus   we   reverse   them   now.   */   

                *p--='\0';                       /*   terminate   string;   p   points   to   last   digit   */   

    do   {   
        temp   =   *p;   
        *p   =   *firstdig;   
                                        *firstdig   =   temp;       /*   swap   *p   and   *firstdig   */   
        --p;   
                                        ++firstdig;                   /*   advance   to   next   two   digits   */   
                                }   while   (firstdig   <   p);   /*   repeat   until   halfway   */   
    }
    void getLine(char s[],int lim)
    {
        FILE * fin = fopen("./test.txt","r");
        char c;
        int i=0;
        int line=0;
        while( i<lim && (fscanf(fin,"%c",&c))!=EOF  ){
            s[i] = c;
            if(c=='\n')
                line++;
            i++;
            printf("%c",c);
        }
        printf("this text has %d lines\n",line);
    }

    void BitwiseOperation(){
    int a = 312 & 0177; // 屏蔽312的非低7位，0177为八进制，对应的二进制位000 001 111 111
    printf("%d\n",a);
    int b = ~077;
    printf("~4 = %d\n",b);
}



void printStu(struct Score s[],int count){
    int i=0;
    printf("----- 原始数据 ------\n");
    for(i=0;i<count;i++){
        printf("%d %s %d\n",s[i].num,s[i].name,s[i].score);
    }
}



void QuickSort(struct Score s[],int left,int right){
    if(left>=right){
        return;
    }
    int l = left;
    int r = right;
    int base = l;
    struct Score tmp = s[left];
    while(left<right){
        while(s[right].score <= s[base].score && left<right)
        {  
            right--;
            if(s[right].score == s[base].score && s[right].num < s[base].num)
            {
                right++;
                break;
            }
        }
        while(s[left].score >= s[base].score && left<right)
            left++;


        if(left < right ){
            /*
            int i = left;
            int j = right;
            int num = s[i].num;
            char name[20];
            strcpy(name,s[i].name);
            int score = s[i].score;

            s[i].num = s[j].num;
            strcpy(s[i].name,s[j].name);
            s[i].score = s[j].score;

            s[j].num = num;
            strcpy(s[j].name,name);
            s[j].score = score;
            */
            struct Score ll = s[left];
            s[left] = s[right];
            s[right] = ll;

        }
    }
    s[l] = s[left];
    s[left] = tmp;
    QuickSort(s,l,left-1);
    QuickSort(s,left+1,r);
}


void QuickSort2(struct Score s[],int left,int right){
    if(left>=right){
        return;
    }
    int l = left;
    int r = right;
    int base = l;
    struct Score tmp = s[left];
    while(left<right){
        while(s[right].num >= s[base].num && left<right)
            right--;
        while(s[left].num <= s[base].num && left<right)
            left++;


        if(left < right ){

            struct Score ll = s[left];
            s[left] = s[right];
            s[right] = ll;

        }
    }
    s[l] = s[left];
    s[left] = tmp;
    QuickSort(s,l,left-1);
    QuickSort(s,left+1,r);
}


void write(FILE * out,struct Score s[],int count){
    int i=0;
    for(i=0;i<count;i++){
        fprintf(out,"%d %s %d\n",s[i].num,s[i].name,s[i].score);
    }
}
// 18年数据结构 第五大题
//五、（本题共 20 分）两个班的成绩分别存放在两个文件当中。 
//每个文件有多行，每行都是由空格分隔的学号、姓名和成绩。
//现在要将两个班的成绩合并到一起进行排序按照成绩从高到低，如果相同则按学号由小到大排序
//将结果输出一个文件当中。两个输入文件名与输出文件名使用命令行参数指定
void Five_18(){
    char * inputFile1 = "./1.txt";
    char * inputFile2 = "./2.txt";
    char * outputFile = "./score.txt";
    FILE  * out = fopen(outputFile,"w");
    
    FILE  * in1 = fopen(inputFile1,"r");
    FILE  * in2 = fopen(inputFile2,"r");
   // fprintf(out,"%s","hello world");
    char  name[20];
    int num;
    int score;
    int i=0;
    int count=0;
    struct Score stu[200];
    while( fscanf(in1,"%d %s %d\n",&num,name,&score)!=EOF  ){
        stu[i].num = num;
       // stu[ii].name = name;
        strcpy(stu[i].name,name);
        stu[i].score  = score;
        i++;
        count++;
    }
    printf("--> %d%d\n",i,count);
    while( fscanf(in2,"%d %s %d\n",&num,name,&score)!=EOF  ){
        stu[i].num = num;
        strcpy(stu[i].name,name);
        stu[i].score  = score;
        i++;
        count++;
    }
    printStu(stu,count);
    QuickSort2(stu,0,count-1);
    QuickSort(stu,0,count-1);
    printStu(stu,count);
    write(out,stu,count);
}


int bitcount(unsigned x){
    int b=0;
    for(b=0; x!=0;x>>=1){
        if(x&01)
            b++;
    }
    return  b;
}



// 从x的第start位开始，取len位数，假定第一位从0开始
int getBits(int x,int start,int len){
    int a = x>>(start-len+1);// 先将期望得到的字段移动到最右端
    int res = a & ~(~0 << len); // ~0所有位全为1，向左移动n位，右边n位用0填补，再取反，右边n位变为1的屏蔽码
    return res;
}

int setbits(int x,int p,int n,int y){
    // 先取出这n位
    int _n = getBits(x,p,n);
    printf("_n = %d\n",_n);
    // 然后将y的右边的n全部变为0
    y = (y>>n)<<n;
    return y | _n;
} // nice 比kr答案简单很多

unsigned int rigthot(unsigned x,int n){
    B2I(x);
    printf("\n");
    unsigned int pb = ~( ~0 << n );
    unsigned int lastN = x & pb;
    printf("lastN = %d\n",lastN );
    B2I(lastN);  
    unsigned int firstN = lastN<<(32-n-1);
    printf("\nfirstN = %d\n",firstN );
    B2I(firstN);
    printf("\n");
    printf("|| %d\n",(x>>n) | firstN);
    return (x >> n) ^ firstN;
}
int main()
{
    unsigned int a = 727;
    unsigned result = rigthot(a,2);
    B2I(result);
    printf("\nresult = %d\n",result);
//     Five_18();
// //    char s[MAXLINE];
// //    getLine(s,MAXLINE);
//     printf("bitcount :%d\n",bitcount(4));
//     char str[] = {'a','b','c','d','e','f','g','h','j','k','\0'};
//     printf("%d\n",'a');
    //reverse(str,10);
//    BitwiseOperation();
//    printf("getBits %d\n",getBits(99,5,5));
//    printf("setbits %d\n",setbits(17,3,3,31));
    return 0;
}


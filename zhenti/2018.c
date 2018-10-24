#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YES 1
#define NO 0
#define MAX 100
#define eps 0.000000000001
typedef struct  Score{
    int num;
    char name[20];
    int score;
}Stu[200];


void printStu(struct Score s[],int count){
    int i=0;
    printf("----- 原始数据 ------\n");
    for(i=0;i<count;i++){
        printf("%d %s %d\n",s[i].num,s[i].name,s[i].score);
    }
}

void print(int b[],int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
}


// 相同成绩学号大的排在前面
void QuickSort(struct Score s[],int left,int right){
     if(left>=right){
        return;
    }
    int l = left;
    int r = right;
    int base = l;
    struct Score tmp = s[base];
    while(left<right){
        while(s[right].score <= s[base].score && left<right ){
            // 如果成绩相等，那么就按照学号从大到小排
            if(s[right].score == s[base].score && s[right].num > s[base].num){
                printf("r :%d,%d ",s[right].score,s[base].score);
                break;
            }
            right--;
        }
        while(s[left].score >= s[base].score && left<right ){
            if(s[left].score == s[base].score && s[left].num < s[base].num){
                printf("l :%d,%d ",s[left].score,s[left].score);
                break;
            }
            left++;
        }

        if(left < right ){
            struct Score ll = s[left];
            s[left] = s[right];
            s[right] = ll;

        }
    }
    s[base] = s[left];
    s[left] = tmp;
    
   // printStu(s, 10);
    QuickSort(s,l,left-1);
    QuickSort(s,left+1,r);
}

 
void QuickSortByIdcard(struct Score s[],int left,int right){
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
    QuickSortByIdcard(s,l,left-1);
    QuickSortByIdcard(s,left+1,r);
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
    char * inputFile1 = "../c_part/1.txt";
    char * inputFile2 = "../c_part/2.txt";
    char * outputFile = "../c_part/score.txt";
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
   // QuickSortByIdcard(stu,0,count-1);
   // printStu(stu,count);
    QuickSort(stu,0,count-1);
    printStu(stu,count);
    write(out,stu,count);
} // 完美解决方案


// 四 利用牛顿迭代法求立方根
float CubeSqrtByNewton(float x)
{
    float val = x;//最终
    float last;//保存上一个计算的值
    do
    {
        last = val;
        val =(2*val + x/(val*val)) / 3;
                                        
    }while(fabs(val-last) > eps);
    return val;

}

// 升序
int Asc(int a,int b){
    // 升序，如果a 》 b 则返回真
    return a>=b;
}

// 降序
int Des(int a,int b){
    return a<=b;
}
// c 第三大题  根据不同的参数，排序规则不同，升或者降
// 快速排序
// compare 排序标准
void SAN_QuickSort(int (*compare)(int ,int ),int arr[],int left,int right){
    if(left>=right)
        return;
    int l = left;
    int r = right;
    int base = arr[l];
    while(left<right){
        while(compare(arr[right],base) && left < right)
            right--;
        while(compare(base,arr[left]) && left < right)
            left++;
        if(left<right){
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    arr[l] = arr[left];
    arr[left] = base;
    //print(arr,10);
    SAN_QuickSort(compare,arr,l,left-1);
    SAN_QuickSort(compare,arr,left+1,r);
}

// 二 从x的第start位开始，取len位数，假定第一位从0开始
int getBits(int x,int start,int len){
    int a = x>>(start-len+1);// 先将期望得到的字段移动到最右端
    int res = a & ~(~0 << len); // ~0所有位全为1，向左移动n位，右边n位用0填补，再取反，右边n位变为1的屏蔽码
    return res;
}
int main(int argc,char *argv[])
{
    printf("%f\n",CubeSqrtByNewton(10));
 //   Five_18();
    // int select = 0;
    // if (argc>1 && strcmp(argv[1],"-a")==0)
    // {
    //     select = 1;
    //     // 0 默认升序，1 降序

    // }
    // //int b[10] = {1,2,3,4,5,6,7,8,9,10};
    // int b[10] = {111111,1234,124,6,1234,1,412,4231,4 ,3};
    // printf("----原始数据------\n");
    // print(b,10); 
    // printf("---------------\n");
    // SAN_QuickSort( (int (*)(int , int))select==0?Asc:Des,b,0,9);
    // print(b,10);
    return 1;
}

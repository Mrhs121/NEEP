#include <stdio.h>
#include <stdlib.h>
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

float SqrtByNewton(float x)
{
    float val = x;//最终
    float last;//保存上一个计算的值
    do
    {
        last = val;
        val =(val + x/val) / 2;
                                        
    }while(abs(val-last) > eps);
    return val;

}
int main()
{
    Five_18();
    return 1;
}

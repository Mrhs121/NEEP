#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../datastruct/myStrcut.h"
#include "./myhead.h"
#define YES 1
#define NO 0
#define MAX 100
#define eps 0.000000000001
#define FALSE 0
#define TRUE 1
typedef struct  Score{
    int num;
    char name[20];
    int score;
}Student;


void printStu(struct Score s[],int count){
    int i=0;
    //printf("----- 原始数据 ------\n");
    for(i=0;i<count;i++){
        printf("%d %s %d\n",s[i].num,s[i].name,s[i].score);
    }
}

static void print(int b[],int n){
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
        while( s[left].score >= s[base].score  && left<right ){
            if(s[left].score == s[base].score && s[left].num < s[base].num){
                printf("l :%d,%d6 ",s[left].score,s[left].score);
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
   
void write(FILE * out,struct Score s[],int count){
    int i=0;
    for(i=0;i<count;i++){
        fprintf(out,"%d %s %d\n",s[i].num,s[i].name,s[i].score);
    }
}

// 839可以使用标准库
int compareStudent(const void * stua,const void * stub){
    Student * a = (Student*)stua;
    Student * b = (Student*)stub;
    if(b->score == a->score){
        return b->num - a->num; 
    }
    return b->score - a->score;
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
    //QuickSort(stu,0,count-1);
    qsort(stu,count,sizeof(Student),compareStudent);
    printf("\n-----after------\n");
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
// 错误
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


int _test(void *arr[],int type,int n,int compare){
    return 1;
}

// 2018 839 判断表b是否包含在a中 时间O(n)
// 理解错误，这个只能测试连续串
int  isAIncludeB(LNode *a,LNode*b)
{
    LNode * _a = a->next;
    LNode * _b = b->next;
    LNode * save = _a;
    // 如果匹配链 首元素的值比目标链的首元素都小
    // 那么肯定不包含
    if(_b->data < _a->data){
        return FALSE;
    }
    while(_a!=NULL){
        if(_a->data == _b->data){
            // 同时移动
            _a = _a->next;
            _b = _b->next;
        } else {
            // 不匹配的情况下 子表复原到表头
            _b = b->next;
            _a = save->next;
            save  = _a;
        }
        // 如果走完了，那么说明吧全部匹配好了
        if(_b==NULL){
            return TRUE;
        }
    }
    if(_a==NULL && _b!=NULL){
        return FALSE;
    } else {
        return TRUE;
    }
    //return FALSE;
}
// 最后一题 打印x的所有的祖先节点
int ancestor(BTree *b,int x)
{
    if (b==NULL){
        return 0;
    }
    else if ( (b->lchild!=NULL && b->lchild->data==x) 
            || (b->rchild!=NULL && b->rchild->data==x))
    {
        printf("%d ",b->data);
        return 1;
    }
    else if ( (ancestor(b->lchild,x)) || (ancestor(b->rchild,x)))
    {
        printf("%d ",b->data);
        return 1;
    }
    else
        return 0;
}

int printAnc(BTree * tree,int key){
    if(tree == NULL){
        return 0;
    }
    if(tree->data == key){
        return 1;
    }
    
    int result =  (printAnc(tree->lchild,key) || printAnc(tree->rchild,key) );
    if(result == 1)
        printf("anc : %d \n",tree->data);
    return result;
    //return 0;
}
void  testAnc(){
    int data[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    BTree * tree;
    tree = createTree(tree,data);
    LeverOrder(tree);
    int where;
    scanf("%d",&where);
    ancestor(tree,where);
}


int inclusion(LNode * a,LNode * b){
    LNode * aa = a->next;
    LNode * bb = b->next;
    while(aa!=NULL && bb!=NULL){
        if(aa->data == bb->data){
            aa = aa->next;
            bb = bb->next;
        } else {
            aa = aa->next;
        }
    }
    if(bb==NULL){
        return 1;
    }
    return 0;
}
void swap(const void* a, const void* b, int size)
{
    assert(a != NULL && b != NULL);
    unsigned char tmp = 0;
    int i = 0;
    // 应为不知道具体元素的类型，所以逐个字节的交换数据，以达到整体交换数据的目的
    while (size > 0) {
        tmp = *((char*)a + i);
        printf("%d\n",tmp );
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
        ++i;
        --size;
    }
}


enum TYPE{INT,FLOAT,CHAR,STR};
typedef enum TYPE Datatype;

// 适用于任何类型
// left 开始位置 right 全部元素的个数
void Qsort(void* base, int left, int right, int size, int (*cmp)(const void* a, const void* b))
{
    assert(base != NULL && size >= 1 && cmp != NULL);    /* left may be < 0 because of the last - 1 */
    if (left >= right) return;
    // 左右指针
    char* pleft = (char*)base + left * size; 
    // 有效的随机取base值，避免有序序列带来的最糟糕情况
    char* pkey = (char*)base + (left + (right - left) / 2) * size;
    
    swap(pleft, pkey, size);
    int last = left;
    char* plast = (char*)base + last * size;
    for (int i = left + 1; i <= right; ++i) {
        char* pi = (char*)base + i * size;
        if (cmp(pi, pleft) < 0) {
            ++last;
            plast = (char*)base + last * size;
            swap(pi, plast, size);
        }
    }
    swap(pleft, plast, size);
    Qsort(base, left, last - 1, size, cmp);
    Qsort(base, last + 1, right, size, cmp);
}

int cmp_string(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    // 指向字符串的指针 *--->char * 
    const char** lhs = (const char**)a;
    const char** rhs = (const char**)b;
    // char ** 解一层引用就是char * 也就是字符串
    return strcmp(*lhs, *rhs);
}

int cmp_int(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
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

int cmp_float(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const double* lhs = (const double*)a;
    const double* rhs = (const double*)b;
    if (*lhs < *rhs) {
        return -1;
    } else if (*lhs == *rhs) {
        return 0;
    } else {
        return 1;
    }
}

void Qsort1(void* base, int left, int right, int size, Datatype type){
    //  可以根据 type的值来调用不用类型的compare
    if (type == INT)
    {
        printf("data type is int\n");
        Qsort(base, left, right, size, cmp_int);
    } else if(type == FLOAT){
        printf("float\n");
    } else if(type == CHAR){
        printf("char\n");
    }
}

int test2018()
{

    int data1[] = {1,2,4,5,6,7,8,9};
    int data2[] = {2,4,9};
    int data3[] = {-1,3,5};
    LNode * a = create(data1,8);
    LNode * b = create(data2,3);
    LNode * c = create(data3,3);
    printf("a - b : %d\n",inclusion(a,b));
    printf("a - c : %d\n",inclusion(a,c));
    //testAnc();
    // 
    // char data = {'a','b','c'};
    // int data2 = {1,2,3};
    // test(data,1);

    //printf("%f\n",CubeSqrtByNewton(10));
    //Five_18();
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
    //SAN_QuickSort( (int (*)(int , int))select==0?Asc:Des,b,0,9);
    //printf("%d\n","abc"-"abd");
    // print(b,10);
    return 1;
}

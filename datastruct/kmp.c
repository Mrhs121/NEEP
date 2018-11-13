#include <stdio.h>
#include <stdlib.h>



void printArr(int * arr,int n){
    int i = 0;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int *_next; 
//这里的str是被包含的较短字符串，length是这个字符串的长度。
void calnext(char *str, int *next, int length)
{
    next[0] = -1;
    int k = -1;
    for (int q = 1; q <= length-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])
        {
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q])//如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;
    }
}


// str 正文串
// prt 模式串（短串）
// 核心：长串不发生回溯
int KMP(char *str, int slen, char *ptr, int plen)
{
    int *next = (int *)malloc(sizeof(int)*plen);
    calnext(ptr, next, plen);//计算next数组
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i]){//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
         
            k = next[k];//往前回溯
    //        printf("回溯  k = %d\n",k);
        }
        // 处理匹配的情况
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//说明k移动到ptr的最末端
        {
            //cout << "在位置" << i-plen+1<< endl;
            //k = -1;//重新初始化，寻找下一个
            //i = i - plen + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            return i-plen+1;//返回相应的位置
        }
    }
    return -1;  
}

void testKMP(){
     printf("kmp 算法\n核心思想：如何不让text的指针不回溯\n");
    _next = (int *)malloc(sizeof(int)*100);
    char * patten = "abababac";
    char * text = "abacababababacababc";
    printf("text  :%s\npatten:%s\n",text,patten);
    calnext(patten,_next,8);
    printArr(_next,8);
    int index = KMP(text,19,patten,8);
    printf("finded index is :%d\n",index);
    
}

int getLength(char * str)
{
    int length = 0;
    int i = 0;
    while(str[i++]!='\0'){
        length++;
    }
    return length;
}


int getLine(char str[100],FILE * in)
{
    char c;
    int i = 0;
    int result = 1;
    while( (result=fscanf(in,"%c",&c))!=EOF && c!='\n'){
        str[i++] = c;
    }
    str[i] = '\0';
    return result;

}
// 使用kmp实现的grep程序
void grep(char * from,char * msg){

    FILE * in = fopen(from,"r");
    char message[100];
    int msg_len = getLength(msg);
    int lines = 1;
    while(getLine(message,in)!=EOF){
        //printf("%s\n",message);
        if(KMP(message,getLength(message),msg,msg_len)!=-1 ){
            printf("%d:%s\n",lines,message);
        }
        lines++;
    }
    printf("---------over!----------\n");
}
int main(int argc,char *argv[]){
    if(argc==3){
        grep(argv[1],argv[2]);
    } else {
        printf("usage: grep [filename] [patten]\n");
    }
    
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./myhead.h"
int _hash(const char *str){
    int sum=0;
    int i = 0;
    char c;
    if(str == NULL)
        return -1;
    while ( (c=str[i++])!='\0') {
        sum+=c;
    }
    return sum%10007;
}

// qsort 用于二维字符串数组的排序
int compare(const void * strA,const void * strB){
    // 注意这里的写法，先转换成二级指针，再解一层引用
    char * a = *(char**)strA;
    char * b = *(char**)strB;
   // printf("compare %s %s\n",a,b);
    int hashA = _hash(a), hashB = _hash(b);
    if(hashB!=hashA){
        //printf("hash\n");
        return hashA - hashB;
    }
    else {
        if(strlen(a)!=strlen(b)){
            //printf("len\n");
            return strlen(b)-strlen(a);
        }
        else{
            //printf("cmp\n");
            return strcmp(b,a);
        }
    }
    return 1;
}

void quicksort(char *data[],int left,int right){
    if(left>=right){
        return;
    }
    int base_hash = _hash(data[left]);
    int l=left,r=right;
    
    while (left<right) {
        while (_hash(data[right])>=base_hash && left<right) {
            if(_hash(data[right])==base_hash ){
                if(strlen(data[right])==strlen(data[l])){
                    if(strcmp(data[right], data[l])>0){
                        break;
                    }
                } else if(strlen(data[right])>strlen(data[l])){
                    break;
                }
            }
            right--;
        }
        while (_hash(data[left])<=base_hash && left<right) {
            if(_hash(data[left])==base_hash ){
                if(strlen(data[left])==strlen(data[l])){
                    if(strcmp(data[left], data[l])<0){
                        break;
                    }
                } else if(strlen(data[left])>strlen(data[l])){
                    break;
                }
            }
            left++;
        }
        //printf("%d,%d",left,right);
        char * temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        
    }
    //  交换基准元素
    
    char * base = data[l];
    data[l] = data[left];
    data[left] = base;
    quicksort(data, l, left-1);
    quicksort(data, left+1, r);
} // 没有bug了

void testQuickSort(){
    char *str[1000] = {"abfffc","acgb","agcb","cabgh"};
    int i =0;
    for(i=0;i<4;i++){
        printf("%s:%d\n",str[i],_hash(str[i]));
    }
//    printf("%d\n",strcmp("abc", "bbc"));
    //quicksort(str,0,3);
    qsort(str,4,sizeof(str[0]),compare);
    for(i=0;i<4;i++){
        printf("%s\n",str[i]);
    } 
}
//直接传递二位数组就完事了
int split(char key,char * str,char result[][1000]){
    char c;
    int i = 0;
    int line= 0;
    int column = 0;
    while( (c=str[i++])!='\0' )
    {
        if(c!=key){
            *(((char*)result)+line*1000+column) = c;
            column++;
            *(((char*)result)+line*1000+column) = '\0';
        } else {
            column = 0;
            line++;
        }
    }
    printf("line = %d\n",line+1);
    return line+1;
}
void testsplit(char _key){
    char key = _key;
    char result[100][1000];
    int lines = split(key,"hu=ang da shen,li.ai.li,bao-b a o , zhu=zhu",result);
    int i = 0;
    for(i=0;i<lines;i++){
        printf("%s\n", result[i]);
    }
}
int test2014()
{
    testQuickSort();
    //compare("huangsheng","dashen");
	return 1;
}

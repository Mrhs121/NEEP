#include <stdio.h>
#include <stdlib.h>


int _hash(char *str){
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

int main()
{
    char *str[] = {"abc","bac","acb","cab"};
    int i =0;
    for(i=0;i<4;i++){
        printf("%d\n",_hash(str[i]));
    }
//    printf("%d\n",strcmp("abc", "bbc"));
    quicksort(str,0,3);
    for(i=0;i<4;i++){
        printf("%s\n",str[i]);
    }
	return 1;
}

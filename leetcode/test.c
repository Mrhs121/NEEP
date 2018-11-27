#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 最长不重复子串
int lengthOfLongestSubstring(char* s) {
    //if(ste)
    if(strlen(s)==0)
        return 0;
    if(strlen(s)==1)
        return 1;
    int check[127] = {0};
    int index[127] = {0};
    int length = 0,i = 0,max = 1,start=0,end = 0,j=0;
    char c;
    while( (c=s[i]) != '\0'){
        if(check[c]==0){
            length++;
            index[c] = i;
            check[c] = 1;
        } else {
            //printf("--\n");
            if(max<=length){
                max = length;
                end = i;
            }
            length = length-index[c]+start;
            for(j=start;j<index[c];j++)
                check[s[j]] = 0;
            start = index[c]+1; 
            index[c] = i;
            //check[c-97] = 0;
        }
        i++;
       // printf("cur len :%d,max %d\n",length,max);
    }
    if(max<=length){
        max = length;
        end = i;
    }
    printf("end = %d\n",end);
    return max;
}
// 返回最便宜的方案
int shoppingOffers(int* price, int priceSize, int** special, int specialRowSize, int *specialColSizes, int* needs, int needsSize) {
    
}
int main(){

    //printf("%d\n",lengthOfLongestSubstring("aiuiothgfksanv"));
    return 0;
}
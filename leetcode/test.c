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
    return 1;
}


char * dest;
// 最长回文子串
char *  longestPalindrome(char* s) {
    int length = strlen(s);
    printf("%d\n",length);
    int i =0 ,j =0;
    int start = 0;
    int maxlength = 0,maxlength2=0;
    int final=0,finallength=0;
    // 有两种情况，单核串 双核串
    for(i=0;i<length;i++){
        if(i==11){
            
        }
        if(s[i+1] == s[i]){
            // 双核
            maxlength =2;
            int a =(i<=length/2)?i:length-1-i;
            
            for (j = 1; j<=a; j++)
            {
                if(s[i-j] == s[i+1+j]){
                    maxlength += 2;
                }
                else
                    break;
            }
            //final = max>final?max:final;
            start = maxlength>finallength?(i-j+1):start;
            finallength = maxlength>finallength?maxlength:finallength;
        } //else {
            // 单核
            //max = 1; // 保底为2
            maxlength2 =1;
            int b =(i<=length/2)?i:length-1-i;
            for (j = 1; j<=b; j++)
            {
                if(s[i-j] == s[i+j]){
                    //max++;
                    maxlength2 += 2;
                }
                else
                    break;
            }
        
            maxlength = maxlength>maxlength2?maxlength:maxlength2;
            start = maxlength>finallength?i-j+1:start;
            finallength = maxlength>finallength?maxlength:finallength;
        //}
         printf("finallength = %d , start = %d\n",finallength,start);
    }
    printf("finallength = %d , start = %d\n",finallength,start);
    char * dest = (char*)malloc(sizeof(char)*finallength+1);
    dest[finallength] = '\0';
    strncpy(dest,s+start,finallength);
    return dest;
}

int main(){
    
    //bbcdyxabaxyda
    
    printf("%s\n",longestPalindrome("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"));
    //printf("Max Length = %d\n",maxlength);
    //printf("%d\n",lengthOfLongestSubstring("aiuiothgfksanv"));
    return 0;
}

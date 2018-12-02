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



// 最长回文子串
int  longestPalindrome(char* s) {
    int length = strlen(s);
    int i =0 ,j =0;
    int max = -1;
    int maxlength = 0;
    int final=0,finallength=0;
    // 有两种情况，单核串 双核串
    for(i=0;i<length;i++){

        if(s[i+1] == s[i]){
            // 双核
            max = 2; // 保底为2
            maxlength =2;
            for (j = 1; j<=(i<length/2)?i:length-1-i; j++)
            {
                if(s[i-j] == s[i+i+j]){
                    //max++;
                    maxlength += 2;
                }
                else 
                    break;   
            }
            //final = max>final?max:final;
            final = maxlength>finallength?i:final;
            finallength = maxlength>finallength?maxlength:finallength;
        } else {
            // 单核
            //max = 1; // 保底为2
            maxlength =1;
            for (j = 1; j<=(i<length/2)?i:length-1-i; j++)
            {
                if(s[i-j] == s[i+j]){
                    //max++;
                    maxlength += 2;
                }
                else 
                    break;   
            }

            finallength = maxlength>finallength?maxlength:finallength;
            final = maxlength>finallength?i:final;
        }

    }
    return final;
}

int main(){


    int maxlength = longestPalindrome("bbcdyxabaxyda");
    printf("Max Length = %d\n",maxlength);
    //printf("%d\n",lengthOfLongestSubstring("aiuiothgfksanv"));
    return 0;
}
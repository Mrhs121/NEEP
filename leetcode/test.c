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


//char * dest;
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
// 寻找最长公共前缀
char* longestCommonPrefix(char** strs, int strsSize) {
    char c = strs[0][0];
    int i = 0, j = 0;
    int count = 0;
    int length = 0;
    while(c!='\0'){
        c = strs[0][i];
        for(j=0;j<strsSize&&c!='\0';j++){
            if(c==strs[j][i]){
                count++;
            }
        }
        printf("count = %d\n",count );
        if(count==strsSize){
            count = 0;
            length++;
        }
        else
            break;
        i++;
    }
    printf("length = %d\n",length );
    char * dest = (char*)malloc(sizeof(char)*length+1);
    dest[length] = '\0';
    for(i=0;i<length;i++){
        dest[i] = strs[0][i];
    }
    printf("%s\n",dest );
    return dest;
}
int compare(const void * a,const void * b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    //printf("%d %d\n",num1,num2);
    return num1 - num2;
}
void print(int arr[],int size){
    int i = 0;
    for(i=0;i<size;i++){
        printf("%d ",arr[i] );
    }
    printf("\n");
}
// 三数之和等于0
int** threeSum(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(nums[0]),compare);
    //print(nums,numsSize);
    int *result[3];
    int lines = 0;
    int i=0,j=0,k=0;
    //int a,b,c;
    for(i=0;i<numsSize;i++){
        for(j=i+1;i<numsSize;j++){
            for(k=j+1;k<numsSize;k++){
                if(nums[i]+nums[j]+nums[k] == 0){
                    result[lines][0] = nums[i];
                    result[lines][1] = nums[j];
                    result[lines][2] = nums[k];
                    lines++;
                }
            }  
        }
    }
    printf("%d\n",lines );
    *returnSize = lines;
    return result;
}
int main(){
    
    int size;
    int data[] = {-1, 0, 1, 2, -1, -4};
    threeSum(data,6,&size);
    char * strs[20] = {"huangsheng","huangdashen","huanle"}; 
    //printf("%s\n",longestCommonPrefix(strs,3));
    //bbcdyxabaxyda
    
    //printf("%s\n",longestPalindrome("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"));
    //printf("Max Length = %d\n",maxlength);
    //printf("%d\n",lengthOfLongestSubstring("aiuiothgfksanv"));
    return 0;
}

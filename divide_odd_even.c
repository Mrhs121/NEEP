/*************************************************************************
	> File Name: divide_odd_even.c
	> Author:黄大神 
	> Mail: 
	> Created Time: Sat 22 Sep 2018 07:18:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void divide(int arr[],int left,int right){

    int base = arr[left];
    int l = left;
    int r = right;
    int temp;
    while(l<r){
        while(arr[r]%2==0 && l<r){
            r--;
        }
        while(arr[l]%2!=0 && l<r){
            l++;
        }
        // 当左边遇到偶数的时候，右边遇到奇数的时候，交换
        printf("swap %d <-- >%d\n",r,l);
        if(arr[l]%2==0&&arr[r]%2!=0){
            temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }   
    }   
}


// 时间复杂度O(n) 空间复杂度O(1)
int main()
{
    int arr[7] = {1,1,1,2,2,2,2};
    divide(arr,0,6);
    int i=0;
    for(i=0;i<7;i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
    return 0;
}


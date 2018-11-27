#include <stdio.h>
#include <stdlib.h>
#define LOW 1
#define UP 2

static int count = 0;
// 寻找给定上下边界的下标
int binsearch(int data[],int key,int l,int r,int lowOrUp){
	
	if(key>data[r] && lowOrUp == LOW)
		return -1;
	if(key<data[0] && lowOrUp == UP)
		return -1;
    //printf("key = %d,l=%d,r=%d\n",key,l,r );
    int left = l,right = r;
    if(l>r)
        return -1;
    int mid = 0;
    while(l<=r){
    	count++;
        mid = (l+r)/2;
        if(data[mid]>key){
            r = mid-1;
        } else if(data[mid]<key){
            l = mid+1;
        } else {
            //处理key有重复的情况
            if(lowOrUp==LOW){
                if(data[mid-1]==key){
                    return binsearch(data,key,left,mid-1,LOW);
                } else {
                    return mid;
                }
            } else {
                if(data[mid+1]==key){
                    return binsearch(data,key,mid+1,right,UP);
                } else {
                    return mid;
                }
            }
        }
    }
        return mid;
}


int main(){
    int data[] = {1,3,3,3,4,
        4,4,4,4,4,
        4,4,4,4,5,
        5,5,5,7,8,
        9,10,11,11,11,
        11,11,11,13,13};

    int i =0;
    for(i=0;i<30;i++){
        printf("%2d ",i);
    }
    printf("\n");
    for(i=0;i<30;i++){
        printf("%2d ",data[i]);
    }
    int a,b;
    printf("\nINPUT:");
    scanf("%d %d",&a,&b);
    printf("\n");
    int low = binsearch(data,a,0,29,1);
    int up = binsearch(data,b,0,29,2);
    for(i=low;i<=up;i++){
    	printf("%2d ",data[i]);
    }
    printf("\ntime = %d\n",count);

}

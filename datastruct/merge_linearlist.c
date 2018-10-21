#include <stdio.h>

#define MAXSIZE 100
/**
 *
 *
 * 王道22面第七题
 * 结果可行
 *
 */

typedef struct{
	int data;
}Element;

typedef struct{
	int data[MAXSIZE];
	int length;
}SqList;


void merge(SqList A,SqList B,SqList C)
{
	int i=0,j=0,k=0;
	while(i<A.length&&j<B.length)
	{
		if(A.data[i]<=B.data[j])
			C.data[k++] = A.data[i++]; 
		else 
			C.data[k++] = B.data[j++];
	}
	while(i<A.length){
		C.data[k++] = A.data[i++];	
	}
	while(j<B.length ){
		C.data[k++] = B.data[j++];
	}

	C.length = k+1;
//	return ture;


}


void move(SqList * A,int current){
    int len = A->length;
    int i;
    for(i=len-1;i>current;i--){
        A->data[i] = A->data[i-1]; 
    }
}
// 17年839真题  合并两个有序的数组，不使用缓冲区，A的长度够长
// 在A中插入新的元素之后，后面的元素往后面移动即可，应为A 的长度够长
void mergeWithoutBuffer(SqList *A,SqList *B)
{
    void print(int arr[],int n);
	int i=0,j=0;
	while(i<A->length&&j<B->length)
	{
		if(A->data[i]<=B->data[j])
	        i++;
        else{ 
            A->length++;
            move(A,i);
            A->data[i] = B->data[j];
            print(A->data,A->length);
            i++;
            j++;
	    }
    }
    printf("i=%d,j=%d\n",i,j);
	while(j<B->length ){
	    printf("add B\n");
        A->data[i++] = B->data[j++];   
        A->length++;
    }

//	return ture;
}
// 答案存在问题
void meger_839_15(int a[],int n,int b[],int m){
    void print(int a[],int n);
    int i; // recoder b
    int j; // recoder a
    for(i=0;i<m;i++){
        for(j=i+n-1;j>=0&&b[i]<a[i];--j){
             a[i+1] = a[j];
             print(a,7);
        }
        a[j+1] = b[i];
        print(a,7);
    }
}




void reverse(int A[],int left,int right,int size){
	
	if(left>=right || right>=size){
		return;
	}	
	int mid = (left+right)/2;
	for(int i=0;i<mid-left;i++){
		int temp = A[left+i];
		A[left+i] = A[right-i];
		A[right-i] = temp;
	}
	

}
void print(int arr[],int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%5d",arr[i]);
	}
	printf("\n-----------------------------------\n");
}

void searchExchangeInsert(int a[],int size,int find){
	int low=0,high=size-1,mid=0,i;
	while(low<=high){
		mid = (low+high)/2;
		if(a[mid] == find) break;
		else if(a[mid]<find) low=mid+1;
		else if(a[mid]>find) high=mid-1;
	}
	if(a[mid] == find && mid!=size-1){
		int temp = a[mid+1];
		a[mid+1] = a[mid];
		a[mid] = temp;
	} 
	if(low>high){
		printf("not find ,moving arr\n");
		for(i=size;i>high;i--){
			a[i+1] = a[i];
		}
		a[i+1] = find;
	}	


}


int findMid(int size,int a[],int b[]){
	int i=0,j=0,k=0;
	int middata=-1;
	int midindex = size-1;
	while(i<size && j<size){
		if(a[i]<b[j]){
			middata = a[i];
				
			if(k==midindex && i!=size){ 
				printf("shang return\n");
				return middata;}
			i++;
			k++;

		} else {
			
			middata = b[j];
			if(k==midindex && j!=size){ printf("xia return\n");
				return middata;}
			j++;
			k++;

		}
	}
	
	if(i==size){
		printf(" a is over");
		return b[0];
	}
	if(j==size){
		return a[0];
	}
    return  -1;
	// 复杂度O(n);
	
}
void testWithOutBuffer(){

	int b[5] = {11,13,15,17,19};
    SqList A,B;
	int a[5] = {2,4,6,7,8};
    A.length = 0;
    B.length = 0;
    int i;
    for(i=0;i<5;i++){
        A.data[i] = a[i];
        A.length++;
    }
    //A.data[0] = 1000;
    printf("test-->%d\n",A.data[0]);
	for(i=0;i<5;i++){
        B.data[i] = b[i];
        B.length++;
    }
    print(a,5);
    print(b,5);
    mergeWithoutBuffer(&A,&B);
    printf("\n meger result: A len = %d :",A.length);
    for(i=0;i<A.length;i++){
        printf("%3d",A.data[i]);
    }
 
}
int main()
{
    int a[100] = {1,2,4,5};
    int b[3] = {3,7,8};
    meger_839_15(a,4,b,3);
    print(a,7);
   //int middata = findMid(5,a,b);
	//printf("the middata is :%d\n",middata);
	//int a[100] = {1,2,3,4,5,6,7,100,101,102};
	//searchExchangeInsert(a,10,77);
	//print(a,11);
	/*print(a,10);
	reverse(a,0,9,10);
	print(a,10);
	reverse(a,0,2,10);
	print(a,10);
	reverse(a,3,9,10);
	print(a,10);
*/
/*	
 *
	int i=0;
	SqList A;
	A.length = 5;
	SqList B;
	B.length = 6;
	SqList C;
	for(i=0;i<5;i++){
		A.data[i].data = i;
	}
	
	for(i=0;i<6;i++){
		B.data[i].data = i+3;
	}
	printf("----------------  合并两个有序顺序表 --------------\n");
	merge(A,B,C);	
	for(i=0;i<C.length-1;i++){
		printf("%3d",C.data[i].data);
	}
	printf("\n-------------------------------------------\n");
*/
    printf("\n");
	return 0;

	}

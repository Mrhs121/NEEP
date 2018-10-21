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
	Element data[MAXSIZE];
	int length;
}SqList;


void merge(SqList A,SqList B,SqList &C)
{
	int i=0,j=0,k=0;
	while(i<A.length&&j<B.length)
	{
		if(A.data[i].data<=B.data[j].data)
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

// 17年839真题  合并两个有序的数组，不使用缓冲区，A的长度够长
void mergeWithoutBuffer(SqList A,SqList B,SqList &C)
{
	int i=0,j=0,k=0;
	while(i<A.length&&j<B.length)
	{
		if(A.data[i].data<=B.data[j].data)
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
	// 复杂度O(n);
	
}
int main()
{

	int a[5] = {11,13,15,17,19};
	int b[5] = {2,4,6,20,30};
	int middata = findMid(5,a,b);
	printf("the middata is :%d\n",middata);
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
	return 0;

	}

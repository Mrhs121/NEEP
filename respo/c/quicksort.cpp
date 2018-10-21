#include <iostream>
using namespace std;


/*
* 
*	此项目完全正确！
*
*
*/

int data[5] = {5,9,2,1,8};
// shengxu 
void quicksort(int arr[],int left,int right)
{
  if(left>right)
  {
  		return;
  }
  void print(int a[]);
  //print(arr);	
  int base = arr[left];
  int l = left;
  int r = right;

  
  while(l!=r)
  {
  		// 从后面招到一个比他小的数  
  		while(arr[r]>=base && l<r)
  		{		//cout<<"r move"<<endl;
  				r--;
  		}
  		while(arr[l]<=base && l<r)
  		{
  				l++;
 	 	}
 		//交换这两个数
 		cout<<"l and r:"<<l<<" "<<r<<endl;
 		if(l<r){
			cout<<"swap"<<arr[l]<<" and "<<arr[r]<<endl; 
			int tmp = arr[l];
    			arr[l] = arr[r];
     			arr[r] = tmp;
		//print(arr);
		}
	
    }
  // 基准变量归位
  arr[left] = arr[l];
  arr[l] = base;
  cout<<"yi tang jie shu"<<endl;
  print(arr);
  cout<<"test"<<endl;
  quicksort(arr,left,l-1);
  quicksort(arr,l+1,right);

}

void print(int a[])
{
		for(int i=0;i<5;i++){
				cout<<a[i]<<" ";
		}
     cout<<endl;  
}	
  
int main()
{
  	print(data);
	quicksort(data,0,4);
	cout<<"\n ————————— the new data ———————————"<<endl;
	print(data);
	return 0;
}

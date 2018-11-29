#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "./myStrcut.h"

void print(int b[],int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%5d",b[i]);
    }
    printf("\n");
}

void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertSort(int arr[],int length){
    int i,j;
    int temp = arr[0];
    for(i=1;i<length;i++){
        // 如果小于前驱那么进行插入
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            for(j=i-1;temp<arr[j]&&j>=0;j--){
               //swap(&arr[j],&arr[j-1]);
               arr[j+1] = arr[j];
            };
            arr[j+1] = temp;
            /*另一种实现
             *for(j=i;a[j]<a[j-1]&&j<0;j--){
                    swap(&a[j],a[j-1]);
             }
             *
            */
        }  
    }
}

//  折半插入
void HalfInsertSort(int arr[],int n){
    if(n<=1){
        return;
    }
    int count=1;
    int temp;
    int i,j,mid,left,right;
    for(i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            left = 0;
            right = i-1;
            while(left<=right){
                mid = (left + right)/2;
                if(temp<arr[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            //arr[mid] = temp;
            for(j=i-1;j>=mid;j--){
                arr[j+1] = arr[j];
            }
            arr[mid] = temp;
            printf("第%d次: ",count++);
            print(arr,10);            
        }
    }
}
// 双向 冒泡
void dobule_pop(int arr[],int n){
    
}
// 快速排序
void QuickSort(int arr[],int left,int right){
    if(left>=right)
        return;
    int l = left;
    int r = right;
    int base = arr[l];
    while(left<right){
        while(arr[right]<=base && left < right)
            right--;
        while(arr[left]>=base && left < right)
            left++;
        if(left<right){
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    arr[l] = arr[left];
    arr[left] = base;
    print(arr,10);
    QuickSort(arr,l,left-1);
    QuickSort(arr,left+1,r);
}

// 选择排序
// Time O(n^2) 
// Space O(1)
void selectSort(int arr[],int length){
    if(length <= 1){
        return;
    }
    int i,j,index;
    int _min;
    for(i=0;i<length-1;i++){
        _min = arr[i];
        index = i;
        for(j=i;j<length;j++){
            if(arr[j]<_min){
                _min = arr[j];
                index = j;
            }
                
        }
        //min = 9999;
        swap(&arr[i],&arr[index]);
    }
}

// 查找一个无序的序列中第k个最小的
int find_k_min(int arr[],int low,int high,int k){
    int pivot = arr[low];
    int l=low,r=high;
    while(low<high){
        while(arr[high]>=pivot && low<high){
            --high;
        }
        while(arr[low]<=pivot&&low<high){
            ++low;
        }
        int temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;

    }
    arr[l] = arr[low];
    arr[low] = pivot;
    if(low==k){
        return arr[k-1];
    }
    else if(low>k){
        return find_k_min(arr,l,low-1,k);
    } else {
        return find_k_min(arr,low+1,r,k);
    }
}



// 调整堆
void AdjustDown(int arr[],int k,int length){
    arr[0] = arr[k];
    int i;
    // 从当前结点向下调整的时候，会沿着这条路径一直往下
    // 判断，判断是否调整上层之后会影响下层的结构，如果回
    // 则继续向下调整。
    for(i=2*k;i<=length;i*=2){
        if(i<length&&arr[i]<arr[i+1])
            i++;
        if(arr[0] >= arr[i])
            break;
        else {
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}

// 大顶堆
void buildHeap(int arr[],int length){
    int i;
    for(i=length/2;i>0;i--){
        AdjustDown(arr,i,length);
    }
}

//堆排
// O(nlog2 n)
void testHeap(){
    int arr[] = {-1,123,4123,134,5,512,2,55,61,12,13,14,34};
    print(arr,13);
    int i=0;
    // len为有效数据 的长度,except a[0]
    int len = 12;
    buildHeap(arr,len);
    for(i=len;i>=1;i--){ 
        printf("%5d",arr[1]);
        swap(&arr[1],&arr[i]);
        AdjustDown(arr,1,i-1);
    }
    printf("\n");
    //print(arr,9);
}

// test include   custom headfile
void testHeadFile(){
    int data[5] = {6,5,4,3,2};
    LNode * list = create(data,5);
    printf("%d\n",list->next->data);
}

void printList(LNode * list){
    LNode * p = list;
    if(list->data==-1){
        p = p->next;
    }
    while(p!=NULL){
        printf("%5d->",p->data);
        p = p->next;
    }
    printf("\n");
}
void testListSelectSort(){
    int data[10];
    int i = 0;
    srand(time(NULL));
    for(i=0;i<10;i++){
         data[i] = rand()%100;
    }
    LNode * list = create(data,10);
    printList(list);
    LNode  *q,*p,*t,*h,*pre,*min_pre;
    pre = list;
    q = pre->next;
    while(q!=NULL){
        printf("--->next\n");
        p = q;
        // 在链表中找到最小的结点
        min_pre = pre;
        //printf("current :%d\n",q->data);
        while(p->next!=NULL){
            if(p->next->data < min_pre->next->data){
                min_pre = p;
            }
            p = p->next;
        }

        if(min_pre != pre){
            //  交换两个结点
            t = min_pre->next->next;
            h = pre->next->next;
            LNode * min = min_pre->next;
            LNode * swap = pre->next;
            min->next = h;
            swap->next = t;
            pre->next = min;
            min_pre->next = swap;
        }
        printList(list);
        pre = pre->next;
        q = pre->next->next;
    }
    printList(list);
}
//  链表的选择排序
void ss(){
  int data[10];
    int i = 0;
    srand(time(NULL));
    for(i=0;i<10;i++){
         data[i] = rand()%(rand()%100)+1;
    }
    LNode * list = createWithoutHead(data,10);
    printList(list);
    LNode  *h=list,*p,*pre,*max_pre,*max;
    list = NULL;
    while(h!=NULL){
        p=max=h;
        pre=max_pre=NULL;
        while(p!=NULL){
            // 移动p
            if(p->data>max->data){
                max = p;
                max_pre = pre;
            }
            pre = p;
            p = p->next;
        }
        // 摘链，关键如何处理好pre
        if(max==h){
            h = h->next;
        } else {
            // 摘下当前最大的结点
            // h逐渐减少
            max_pre->next = max->next;
        }

        //printList(list);
        //没有haed的链表的头插法，随后的序列为剩序
        max->next = list;
        list = max;
        if(h!=NULL)
            printList(h);
        // 当 h 上的结点全部取下来之后，结束循环
    }
   printList(list);
}



void mergeAndDistinct(){
    int a[] = {5 ,1, 4, 1, 2, 9};
    int b[] = {7 ,2 ,3 ,1 ,5 ,7 ,6 ,5};
    selectSort(a,6);
    selectSort(b,8);
    print(a,6);
    print(b,8);
    int reslut[40];
    int i=0,j=0;
    int k = 0;
    int dub = -1;
    while(i<6 && j<8){
        if(a[i]<=b[j]){
            if(a[i] == b[j] || a[i]==dub){
                dub = a[i];
                //i++;
                if(a[i] == b[j])
                    j++;
                i++;
            } else if(a[i] != reslut[k-1]) {
                dub = -1;
                reslut[k++] = a[i];
                i++;
            }
            
        } else if(a[i] > b[j] ) {
            if(b[j]!=reslut[k-1])
                reslut[k++] = b[j];
            j++;
        } 
        
    }
    print(reslut,k);
    // 3 4 5 6 7 9
    if(i==6 && j!=8){
        for(i=j;i<8;i++)
        {    
            if(reslut[k-1] == b[i])
                continue;
            reslut[k++] = b[i];
        }   
    } else if(j==8 && i!=6) {
        for(j=i;j<6;j++)
        {   
            if(a[j]==reslut[k-1])
                continue;
            reslut[k++] = a[j];
        }    
    }
    print(reslut,k);
    // for(i=1;i<k;i++){
    //     if(reslut[i] == reslut[i-1] || reslut[i]==reslut[(i+1)%k])
    //         continue;
    //     printf("%d ",reslut[i]);
    // }
    printf("\n");

}
int main()
{   
    mergeAndDistinct();
    //ss();
    //testListSelectSort();
//    testHeadFile();
   // testHeap();
    //printf("\n-----------------\n");
  //  int b[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {412,123334,124,6,11234,1,4512,4231,4 ,3};
    // QuickSort(b,0,9);
    // print(b,10);
    
    
//    int k;
 //   scanf("%d",&k);
  //  int k_min = find_k_min(b,0,9,k);
   // printf("%d min = %d\n",k,k_min);
   // selectSort(b,9);
   // print(b,9);
    //printf("k_min = %d\n",k_min);
    //print(b,10);
    //selectSort(b,10);
    //print(b,10);
    //print(b,10);
    //HalfInsertSort(b,10);
    //print(b,10);

    
    return 0;
}


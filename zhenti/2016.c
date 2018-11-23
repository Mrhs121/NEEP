#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../datastruct/tools/mytools.h"
//#include "../datastruct/myStrcut.h"
int bitsSwapRequired(int x,int y){
	int count = 0;
	int i = 0;
	for(i=0;i<32;i++){
		if( (x&(0x1<<i)) ^ (y&(0x1<<i)) ){
			count++;
		}
	}
	return count;
}

int htoi(char *s){
	int num = 0;
	int i = 0;
	int n = 0;
	char c;
	if(s[i]=='0'){
		i++;
		if(s[i]=='x' || s[i]=='X')
			i++;
	}
	while((c=s[i++])!='\0'){
		if(c>='0' && c<='9'){
			num = c-'0';
		} else if(c>='a' && c<='z'){
			num = c-'a'+10;
		} else if(c>='A' && c<='Z'){
			num = c-'A'+10;
		}
		n = 16*n+num;
	}
	return n;
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
int main()
{
	printf("%d\n",htoi("abc"));
	ss();
    // int a,b;
	// printf("input a and b:");
	// scanf("%d %d",&a,&b);
	// printf("need swap %d\n",bitsSwapRequired(a,b));
	return 1;
}

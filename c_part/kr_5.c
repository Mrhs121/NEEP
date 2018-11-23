//kr第五章 指针与数组
#include <stdio.h>
#include <stdlib.h>


int add(int a,int b){
	printf("add %d and %d\n",a,b);
	return a+b;
}
int main(int argc, char const *argv[])
{

	int (*p)(int,int) = add;
	int result = p(1,2);
	printf("the result = %d\n",result);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>


// 可行
int MCNuggets(int n){
	if(n==9||n==15||n==20)
		return 1;
	else if(n<9)
		return 0;
	return MCNuggets(n-9)||MCNuggets(n-15)||MCNuggets(n-20);

}
int main()
{

	int a;
	while(1){
		scanf("%d",&a);
		printf("%d\n",MCNuggets(a));
	}
	return 1;
}

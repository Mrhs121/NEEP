#include <stdio.h>
#include <stdlib.h>

void * _calloc(unsigned n,unsigned size){
	unsigned i,nb;
	char * p,*q;
	nb = n*size;
	if( (p = q = malloc(nb)) != NULL){
		for(i=0;i<nb;i++){
			*p++ = 'a';
		}
	}
	return p;
}
int main(){
	int * data = (int *)malloc(sizeof(int)*5);
	printf("%d\n",data[0]);
	int * data2 = (int *)_calloc(4,sizeof(int));
	printf("%d\n", data2[0]);
	return 0;
}
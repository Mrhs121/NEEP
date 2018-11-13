#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include "../datastruct/tools/mytools.h"
void myscanf(char * format,...)
{
	va_list ap;
	char * p,*sval;
	char localformat[1000];
	int c,i,*ival;
	unsigned * uval;
	double * dval;
	i=0;
	va_start(ap,format);
	for(p=format;*p;p++){
		if(*p!='%'){
			localformat[i++]  = *p;
			continue;
		}
		localformat[i++] = '%';
		// 判断是否是字母
		while( *(p+1) && !isalpha(*(p+1)) ){
			localformat[i++] = *++p;
			printf("----\n");
		}
		localformat[i++] = *(p+1);
		localformat[i] = '\0';
		switch(*++p){
			case 'd':
				ival = va_arg(ap,int*);
				scanf(localformat,ival);
				break;
			case 'f':
				dval = va_arg(ap,double*);
				scanf(localformat,dval);
				break;
			case 'c':
				sval = va_arg(ap,char*);
				scanf(localformat,sval);
				break;
		}
		printCharArr2(localformat);
		i = 0;
	}
	va_end(ap);
}

int main()
{

	int a;
	char b;
	int *p = &a; // 原理所在
	scanf("%d",p);
	//myscanf("%d %c",&a,&b);
	printf("%d \n",a);
	return 0;
}
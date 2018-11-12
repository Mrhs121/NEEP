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
		while( *(p+1) && !isalpha(*(p+1)) )
			localformat[i++] = *++p;
		localformat[i++] = *(p+1);
		localformat[i] = '\0';
		printCharArr2(localformat);

	}
}

int main()
{

	int a,b;
	myscanf("a=%dd,b=%d",&a,&b);
	return 0;
}
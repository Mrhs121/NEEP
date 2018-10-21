
#include <stdio.h>

int main()
{
	int c;
	FILE *fp;
	fp = fopen("re.txt","r");


	FILE *ofp;
	ofp = fopen("readme2.txt","w");


	while((c=getc(fp))!=EOF){
		//printf("---------------%c",c);
		//putc(c,ofp);
		fprintf(ofp,"%c",c);
	}


	return 0;
}

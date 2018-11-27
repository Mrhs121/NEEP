#include <stdio.h>
#include <math.h>
#define TURE 1
#define FALSE 0

int isspace(char c){
    if(c==' ')
        return TURE;
    return FALSE;    
}



void printString(char str[]){
    char c;
    int i=0;
    while((c=str[i++])!='\0')
        printf("%c",c);
    printf("\n");
}

void expend(char s1[],char s2[]){
    char c;
    int i,j;
    i = j = 0;
    while(  (c=s1[i++])!='\0'   ){
        if(s1[i]=='-' && s1[i+1]>=c){
            i++;
            while(c<s1[i])
                s2[j++] = c++;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}


void testExtend(){
    char str[] = {' ','h','s'};
    printf("%d %d\n",isspace(str[0]),isspace(str[1]));
    char s1[] = {'a','-','b','-',',','f','-','z'};
    char s2[] = {};
    expend(s1,s2);
    printString(s2);
    printf("Hello world\n");
    //return 0;

}

void printd(int n){
    if(n/10){
        printd(n/10);
    }
    printf("%d-",n%10);
}


static int i=0;
void itoa(int n,char s[]){
    if(n/10)
        itoa(n/10,s);
    s[i++] = (n)%10+'a';
    s[i] = '\0';
}


int main()
{
    char s[100];
    itoa(123,s);
    printf("%s\n",s);
    printf("\n");
    printd(1234);
    printf("\n");
    return 0;
}


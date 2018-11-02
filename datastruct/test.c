#include <stdio.h>


void test()
{

}
void test2(){
    printf("i am god_huang!\n");
}

char ** split(char * str,char key){

    char **a;
    a = (char**)malloc(sizeof(char*)*100);
    int i = 0;
    for(i=0;i<100;i++){
        a[i] = (char*)malloc(sizeof(char)*100);
    }
    i = 0;
    int line = 0;
    int clo = 0;
    char c;
    while( (c=str[i++])!='\0' ){
        if(c!=key){
            a[line][clo++] = c;
        } else {
            line++;
            clo = 0;
        }
    }
    /* 
    int i = 0;
    for(i=0;i<100;i++){
        a[i] = (char*)malloc(sizeof(char*));
    }
    */
    //a[1][0] = 'D';
    return a;
}

int main()
{


    char *a[] = {"nihaoma","heiasdfdsafdafllo","world"};
    
    printf("%s,size:%ld\n",a[0],sizeof(a));
    printf("%s\n",a[1]);
    a[1] = "huangdasheng";

    printf("%s\n",a[1]);
    char *b = "hajhdfjahdkfjadh";
    printf("\n%ld:\n",sizeof(b));
    char **c = split("huangsheng,dashen,sixsix",',');
    printf("%s\n%s\n%s\n",c[0],c[1],c[2]);
    /*
    FILE * fin = fopen("aa.txt","r");
    char a ;
    fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
        fscanf(fin,"%c",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
   fscanf(fin,"%c\n",&a);
    printf("%c\n",a);
*/
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void reset(char ascii[16]){
    int i = 0;
    for(i=0;i<16;i++){
        ascii[i] = '.';
    }
}

void read(char * file){
    FILE * in = fopen(file,"r");
    int i = 0;
    char c;
    char ascii[16];
    int j=0;
    while( fscanf(in,"%c",&c)!=EOF){
        if(c=='\n'){
            fscanf(in,"%c",&c);
        }
        ascii[0] = c;
        printf("%x ",c);

        for(i=1;i<16&&fscanf(in,"%c",&c)!=EOF;i++){
            ascii[i] = c;
            printf("%x ",c);
        }
        for(j=0;j<16;j++){
            printf("%c",ascii[j]);
        }
        reset(ascii);
        printf("\n");
    }
}



void chansform(){
     int i,N,bias=0;
     unsigned char msg[16];
     FILE *fp=fopen("aa.txt","r");
     while(1)
     {
         for(i=0;i<16;i++)
         {
             if(fscanf(fp,"%c",&msg[i])==EOF)
                 break;
         }
         N=i;

         printf("%08x ",bias);
         bias+=0x10;
         for(i=0;i<N;i++)
             printf("%02x ",msg[i]);
         if(N<16)
             for(i=0;i<6-N;i++)
                 printf("   ");
         for(i=0;i<N;i++)
         {
             if(0x20<=msg[i] && msg[i]<=126)
                 printf("%c",msg[i]);
             else
                 printf(".");
         }
         printf("\n");
         if(N<16)

             break;

     }
}

int main(int argc,char*argv[])
{
    chansform();
    /*
    char *a[] = {"nihaoma","heiasdfdsafdafllo","world"};
    
    printf("%s,size:%ld\n",a[0],sizeof(a));
    printf("%s\n",a[1]);
    a[1] = "huangdasheng";

    printf("%s\n",a[1]);
    char *b = "hajhdfjahdkfjadh";
    printf("\n%ld:\n",sizeof(b));
    char **c = split("huangsheng,dashen,sixsix",',');
    printf("%s\n%s\n%s\n",c[0],c[1],c[2]);
    */
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


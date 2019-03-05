#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./myhead.h"
int main(int argc,char *argv[])
{
    if(argc<=1){
        printf("Usage : [year]\n");
        return 0;
    }
    int year = atoi(argv[1]);
    switch(year){
        case 2018:
            test2018();
            break;
        case 2017:
            test2017(argv);
            break;
        case 2016:
            test2016();
            break;
        case 2015:
            test2015();
            break;        
        case 2014:
            test2014();
            break;
        case 2013:
            test2013();
            break;
        case 2012:
            test2012();
            break;
        case 2011:
            test2011();
            break;
        case 2010:
            test2010();
            break;
        case 2009:
            test2009();
            break;
        case 2008:
            test2008();
            break;
        default :
            printf("default test 2018");
            test2018();
        break;
    }
    //tmpest2016();
    //.PKInstallSandboxManager-SystemSoftwarest2018();
    //printf("Hello world\n");
    return 0;
}


#include <stdio.h>


unsigned getBits(int x,int p,int n){
    return  (x>>(p+1-n)) & ~(~0 << n);
}


int main()
{
    int x = 5;
    printf("---> %d\n",getBits(x,1,2));
    printf("Hello world\n");
    return 0;
}


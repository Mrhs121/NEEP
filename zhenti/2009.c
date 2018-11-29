#include <stdio.h>
#include <stdlib.h>
#include "../datastruct/tools/mytools.h"
#include "./myhead.h"

void main_092()
{
	int a = 0, b = 0, c = 0;
	int resulta, resultb, resultc;
	int correcta, correctb, correctc;
	int answer = 0;
	// 按照二进制创建初始数据
	a = (1 << 1) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 8);
	b = (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6) + (1 << 7);
	c = (1 << 0) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 8) + (1
	<< 9);
	B2I(a);
	printf("\n"); 
	B2I(b);
	printf("\n"); 
	B2I(c); 
	printf("\n"); 
	int count = 0;
	// 1111111111 所有可能的情况
	for (answer = 0; answer < (1 << 10); answer ++)
	{
		count++;
		correcta = 0;
		correctb = 0;
		correctc = 0;
		// 处理每一种可能
		// bit : 1 10 100 1000 10000逐位的与原始数据进行对比
		for (int bit = 1; bit < (1 << 10); bit = (bit << 1))
		{
			//count++;
			//加入此位的正确答案为0，bit为1，&之后就为0，如果a的答案为1，那么与1&之后仍然为1
			if ((a & bit) == (answer & bit))
			correcta ++;
			if ((b & bit) == (answer & bit))
			correctb ++;
			if ((c & bit) == (answer & bit))
			correctc ++;
		}
		//printf("count : %d",count);
		if (correcta == 7 && correctb == 7 && correctc == 7){
			printf("finded!\n");
			break;
		}
	}
	printf("count : %d\n",count);
	B2I(answer); 
	printf("\n");
}

 
 int file2H()
 {
     int i,N,bias=0;
     unsigned char msg[16];
     FILE *fp=fopen("./xald.mp3","r");
     while(1)
     {
         for(i=0;i<16;i++)
         {
         	 //printf("reading------\n");
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
     return 0;
 }
int test2009()
{
	file2H();
	//main_092();
	return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print(char data[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%c ",data[i]);
	}
	printf("\n");
}

// 类比2017第三大题 将十进制转为十六进制输出
// 采取递归的方法
void DtoH(int x){
    if(x==0)
        return;
    int Divisor = x/16;
    int mod = x%16;
    DtoH(Divisor);    
    if(mod>=10)// 如果余数大于10则转换为A-F输出
        printf("%c",'A'+(mod-10));
    else 
        printf("%d",mod);
} // 完美解决方案

char * ui2hex(unsigned n,char *s){
	int d;
	int mod;
	int i=0;
	char temp;
	// 常规的计算
	do{
		d = n/16;
		mod = n%16;
		n /= 16;
		if(mod>=10)
			s[i++] = 'A'+(mod-10);
		else
			s[i++] = '0' + mod;
	}while(d!=0);
	s[i] = '\0';
	int length = i-1;
	// 最后将字符串反转即可
	for(i=0;i<=length/2;i++){
		temp = s[i];
		s[i] = s[length-i];
		s[length-i] = temp;
	}
	printf("%s\n", s);
	return s;
}


void putAll(int m,int n,char * data){

}

int strins(char  s1[],int i,char s2[]){
	int m,n,k;
	m = strlen(s1);
	n = strlen(s2);
	// s1 move to back
	for(k=m;k>=i;k--)
		s1[n+k] = s1[k];
	for(k=0;k<n;k++)
		s1[i+k] = s2[k];
	print(s1,m+n);
	return 1;
}

int main()
{
	// char a = 9+'0';
	// printf("%c\n", a);
	// char * s;
	// s = ui2hex(671,s); 
	// printf("hex = %s\n",s);
	char a[20] = {'a','b','e'};
	char b[20] = {'c','d'}; 
	strins(a,2,b);
	return 1;
}

/*************************************************************************
	> File Name: postfix.c
	> Author: 黄大神
	> Mail: 1367467330@qq.com
	> Created Time: Thu 13 Sep 2018 07:31:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>

int value[24] = {1,2,3,4,2,2}; 

// 后缀表达式
int calulate(char postfix[])
{
    int stack[100];
    int top = -1;
    int i = 0;
    int x,y;
    char c = postfix[0];
    while(c!='\0'){
        if(islower(c))
        {
            printf("%c\n",c);
            // 将操作数入栈
            stack[++top] = value[c-'a']; 
        }
        else
        {
            printf("%c\n",c);
            switch(c)
            {
                case '+':
                    //从栈顶取出两个元素
                    x = stack[top--];
                    y = stack[top];
                    stack[top] = x + y;
                    printf("%d\n",stack[top]);
                    break;
                case '-':
                    x = stack[top--];
                    y = stack[top];
                    stack[top] = y - x;
                    printf("%d\n",stack[top]);break;
                case '*': 
                    x = stack[top--];
                    y = stack[top];
                    stack[top] = x * y;
                    printf("%d\n",stack[top])             ;  break;
                case '/':
                    x = stack[top--];
                    y = stack[top];
                    stack[top] = y/x;
                     printf("%d\n",stack[top]);break;
                default : return 1;
            }
       // c = postfix[++i];
    }
     c = postfix[++i];
    }
    return stack[0];
    //return -404;
}

int main()
{
    char postfix[] = {'a','b','+','c','*','d','e','f','*','/','-','\0'};
    //printf("%d,%d",'a'-'a','b'-'a');
    int result = calulate(postfix);
    printf("res = %d\n",result);
    return 0;
}

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 9
#define S_SIZE 9
int higher_precision(char x,char y)
{
    if(x=='^'&&y!='^')
        return 1;
    else if(x=='*'&&y!='*'&&y!='^')
        return 1;
    else if(x=='/'&&y!='*'&&y!='^'&&y!='/')
        return 1;
    else if(x=='+'&&y!='^'&&y!='*'&&y!='/'&&y!='+')
        return 1;
    else if(x=='-'&&y!='^'&&y!='*'&&y!='/'&&y!='+'&&y!='-')
        return 1;
    else
        return 0;
}
void ask()
{
    printf("enter your expression");
}
int i,stack[S_SIZE],top=-1;
char exp[MAX_SIZE],result[MAX_SIZE];
void input()
{
    char c;
    i = 0;
    while((c = getchar()) != '\n')
    {
        exp[i] = c;
        i++;
    }
}
void infix_postfix()
{
    int j=0,k;
    for(k=0;k<MAX_SIZE;k++)
    {
        if(isalpha(exp[k]))
            result[j++]=exp[k];
        else if(exp[k]=='*'||exp[k]=='/'||exp[k]=='+'||exp[k]=='-'||exp[k]=='^')
        {
            while(empty()!=1&&higher_precision(stack[top],exp[k]))
            {
                result[j++]=exp[k];
                pop();
            }
            push(exp[k]);
        }
    }
    while(empty()!=1)
    {
        result[j++]=stack[top];
        pop();
    }
}
void pop()
{
    top--;
}
int empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(char x)
{
    stack[++top]=x;
}
void print()
{
    int a;
    for(a=0;a<MAX_SIZE;a++)
    {
        putchar(result[a]);
    }
}
void main()
{
    ask();
    input();
    infix_postfix();
    print();
}


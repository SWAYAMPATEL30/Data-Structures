#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 10
int stack[size];
int top=-1;

char infix[size];
char postfix[size];
char result[size];
char symbol;
int postfixindex;
int resultfixindex;
void push(int x){
    if(x==size-1){
        printf("String full");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

int pop()
{
    if(top==-1){
        printf("empty stack");
        return -1;
    }
    else{
        return stack[top--];
    }
}

int precedence(char c){
    if(c=='+'|| c=='-'){
        return 1;
    }
    else if(c=='*'|| c=='/'){
        return 2;
    }
    else if(c=='%'|| c=='^'){
        return 3;
    }
    else{
        return -1;
    }
}

int rev(char infix[])
{
    for(int i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        push(symbol);
    }
    for(int i=0;infix[i]!='\0';i++)
    {
        postfix[postfixindex++]=pop();
    }
    printf("%s",postfix);

}

int convert()
{
    for(int i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];
        switch(symbol){
            case '(':
            push(symbol);
            break;

            case ')':
            if(top!=-1 && stack[top]!=')')
            {
                result[resultfixindex++]=pop();
            }
            push(symbol);
            break;

            case '+':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                result[resultfixindex++]=pop();
            }
            push(symbol);
            break;

            case '-':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                result[resultfixindex++]=pop();
            }
            push(symbol);
            break;

            case '/':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                result[resultfixindex++]=pop();
            }
            push(symbol);
            break;

            case '*':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                result[resultfixindex++]=pop();
            }
            push(symbol);
            break;

            default:
            result[resultfixindex++]=symbol;
            break;


        }

    }
    while(top!=-1){
        result[resultfixindex++]=pop();
    }
    printf("%s is resultfix :",result);
    //rev(result);
}

int main()
{
    printf("Enter the string :");
    scanf("%s",infix);

    rev(infix);
   convert();
}

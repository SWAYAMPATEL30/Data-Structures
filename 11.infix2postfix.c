#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<ctype.h>

#define size 20

int stack[size];
int top=-1;

char infix[size];
char postfix[size];
char symbol;

int postfixindex=0;

void push(int x)
{
if(top==size-1)
{
    printf("overflow");
}
else{
    top++;
    stack[top]=x;
}
}

int pop()
{
    if(top==-1){
       printf("empty string");
        return -1;
    }
    else{
        
        return stack[top--];
        
    }
}

int precedence(char x){
    if(x=='-' || x=='+')
    return 1;
    else if(x=='*'|| x=='/')
    return 2;
    else if(x=='%'|| x=='^')
    return 3;
    else
    return -1;
}
int infixtopostfix()
{
    printf("Enter the expression to convert ");
    scanf("%s",infix);

    for (int i=0;infix[i]!='\0';i++){
        symbol=infix[i];

        switch(symbol){


            case '(':
            push(symbol);
            break;



            case ')':
            if(top!=-1&&stack[top]!='(')
            {
                postfix[postfixindex++]=pop();
            }
            pop();
            break;

            case '+':
            if(top!=-1&& precedence(symbol)<precedence(stack[top]))
            {
                postfix[postfixindex++]=pop();
            }
            push(symbol);
            break;

            case '-':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                postfix[postfixindex++]=pop();
            }
            push(symbol);
            break;

            case '*':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                postfix[postfixindex++]=pop();
            }
            push(symbol);
            break;
            
            case '/':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                postfix[postfixindex++]=pop();
            }
            push(symbol);
            break;

            case '^':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                postfix[postfixindex++]=pop();
            }
            push(symbol);
            break;

            case '%':
            if(top!=-1 && precedence(symbol)<precedence(stack[top]))
            {
                postfix[postfixindex++]=pop();
            }
            push(symbol);
            break;
            
            default:
            postfix[postfixindex++]=symbol;
            break;

            
            }
        }
        while(top!=-1){
            postfix[postfixindex++]=pop();
        }

        printf("THE POSTFIX EXPRESSION IS :%s",postfix);

}

int eval()
{
    int result,answer;
    for(int i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];

        if(isdigit(symbol)){
            push(symbol-'0');
        }
        else{
            int num2=pop();
            int num1=pop();

            switch(symbol)
            {
                case '+':
                result=num1+num2;
                break;

                case '-':
                result=num1-num2;
                break;


                case '*':
                result=num1*num2;
                break;

                case '/':
                if(num1>num2){
                result=num1/num2;
                }
                else{
                    printf("Division not posible");
                }
                break;


            }
            push(result);
        }
    }
    answer=pop();
    printf("the answer is :%d",answer);
}

int main()
{
    infixtopostfix();
    eval();
    return 0;

}
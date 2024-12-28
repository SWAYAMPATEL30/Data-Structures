#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 5
char postfix[size];
int postindex=0;

int stack[size];
int top=-1;

void push(int x)
{
    top++;
    stack[top]=x;
}

int pop(){
return stack[top--];}

int postfixeval()
{
    int num1,num2,result,answer;
    printf("Enter the post fix evaluation :");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++){
        char symbol=postfix[i];

        if(isdigit(symbol)){
            push(symbol-'0');
        }

        else{
            num2=pop();
            num1=pop();

            switch(symbol){
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
                if(num1>num2)
                result=num1/num2;
                else
                printf("not possible ");
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
    postfixeval();
    return 0;
}
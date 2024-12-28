#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 10
int stack[size];
int top=-1;

char prefix[size];
char symbol;
char prefixindex;

void push( int x)
{
    if(top==size-1){
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
        printf("Empty");
    }
    else{
        return stack[top--];
    }
}

int eval()
{
    int num1,num2,result,answer;
    printf("Enter the string :");
    scanf("%s",prefix);
    for(int i=0;prefix[i]!='\0';i++){
        symbol=prefix[i];
        if(isdigit(symbol)){
            push(symbol-'0');
        }
        else
        {
            num1=pop();
            num2=pop();
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
                result=num1/num2;
                break;

            }
            push(result);

        }
    }
    answer=pop();
    printf("The answer is %d",answer);
}


int main()
{
    eval();
    return 0;
}

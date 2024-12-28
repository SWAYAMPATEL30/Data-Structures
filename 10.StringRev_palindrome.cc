#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 10
int stack[size];
int top=-1;

char input[size];
char output[size];
int outputindex;

void push(int x)
{
    if(top==size-1){
        printf("stack full");
    }
    else{
        top++;
        stack[top]=x;
    }
}

int pop()
{
    if(top==-1){
        printf("Empty stack ");
        return -1;
    }
    else{

        return stack[top--];
    }
}

int rev()
{
    int p=1;
        printf("Enter the String ");
        scanf("%s",input);

    for(int i=0;input[i]!='\0';i++){
        char symbol=input[i];
        push(symbol);
    }
    for(int i=0;input[i]!='\0';i++)
    {
        output[outputindex++]=pop();
    }
    printf("The Reversed string is %s",output);
    for(int i=0;input[i]!='\0';i++){
        if(input[i]!=output[i]){
            p=0;
            break;
        }
    }
if(p==1)printf("found");
else printf(' not ');
}



int main()
{
    rev();
    return 0;
}
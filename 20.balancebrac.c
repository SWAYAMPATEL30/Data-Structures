#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 10
int infix[size];
int top=-1;
int stack[size];

void push(int x)
{
    if(top==size-1){
        printf("full");
    }
    else{
        top++;
        stack[top]=x;
    }
}
int pop(){
    if(top==-1){
        printf("Empty");
        return 0;
    }
    else{
        return stack[top--];
    }
}
int chec()
{
    printf("Enter the string :");
    scanf("%s",infix);

    for(int i=0;infix[i]!='\0';i++){
        char symbol=infix[i];
        if(symbol=='('|| symbol=='['|| symbol=='{')
        {
            push(symbol);
        }
        else if(symbol==')'|| symbol==']'|| symbol=='}')
        {
            char p=pop();
            if(symbol==')' && p!='('||symbol=='}' && p!='{'||symbol==']' && p!='[')
            {
                printf("Not balace");
            }

        }
    

        
    }
    printf("balance");
}

int main()
{
    chec();
    return 0;
}
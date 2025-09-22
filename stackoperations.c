#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int s[MAX];
void push(int num)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow %d cannot be entered in it",num);
    }
    else
    {
        top++;
        s[top]=num;
        printf("%d is pushed into stack",num);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow , No element cannot be deleted ");
    }
    else
    {

        printf("The element deleted from stack is %d",s[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("No elements are there in Stack to Display");

    }
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",s[i]);
        }
    }
}
int main()
{
    int choice,number;
    while(1)
    {
        printf("\n1. PUSH\n2. POP \n3. DISPLAY \n4. EXIT\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number to push:");
                    scanf("%d",&number);
                    push(number);
                    break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
        default:printf("Invalid Choice");
        }
    }
    return 0;
}

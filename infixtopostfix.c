#include<stdio.h>
#define n 50
int top=-1;
int i,k=0;
char stack[n];
void push(char c)
{
    if(top==n-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=c;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    return stack[top--];
}
char peek()
{
    if(top==-1)
        return -1;
    return stack[top];
}
int precedence(char sym)
{
    switch(sym)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
        default: return 0;
    }
}
void infixtopostfix(char infix[],char postfix[])
{
    char symbol;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':push(symbol);
            break;
            case ')':while(top!=-1 && peek()!='(')
                           {
                               postfix[k++]=pop();
                           }
                           pop();
                           break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': while(top!=-1 && precedence(peek())>=precedence(symbol))
        {
            postfix[k++]=pop();
        }
        push(symbol);
        break;
        default:postfix[k++]=symbol;

        }}
        /*while(top!=-1)
        {
            postfix[k++]=pop();

        }*/

    }

int main()
{
    char infix[n],postfix[n];
    printf("Enter a valid parenthysized infix expression: ");
scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("Postfix Expression:%s",postfix);
    return 0;
}

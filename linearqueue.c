#include<stdio.h>
#define n 5
int queue[n];
int front,rear=-1;

void insert()
{
    if(rear==n-1)
    {
        printf("Queue OverFlow");
        return;
    }
    if(rear==-1)
        front=rear=0;
    else
        rear++;
    int item;
    printf("Enter element to be inserted:");
    scanf("%d",&item);
    queue[rear]=item;
    printf("%d is inserted into queue",item);
}
void delete()
{
    if(front==-1 || front> rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("The element deleted:%d",queue[front]);
    if(front==rear)
        front=rear=-1;
    else
        front++;
}
void display()
{
   if(front==-1 || front> rear)
    {
        printf("No elements to Display");
        return;
    }
    printf("Queue Elements are:");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}
int main()
{
    while(1)
    {
        printf("\n1.Insert\t 2.Delete\t 3.Display\t 4.Exit");
        int choice;
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
                break;
            case 2:{
                delete();
                break;
            }
            case 3:display();
            break;
            case 4:return 0;
            default:printf("Invalid Choice\n");
        }
    }
}

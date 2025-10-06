#include<stdio.h>
#define n 3
int queue[n];
int front=-1;
int rear=-1;

void insert()
{
    if ((rear + 1) % n == front) {
        printf("Queue Overflow\n");
        return;
    }
    int item;
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    if (front == -1)
        front = 0;
    rear = (rear + 1) % n;
    queue[rear] = item;
    printf("%d is inserted into queue\n", item);
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
        front=(front+1)%n;
}
void display()
{
   if(front==-1 || front> rear)
    {
        printf("No elements to Display");
        return;
    }
    printf("Queue Elements are:");
    int i=front;
    while(1)
    {
        printf("%d ",queue[i]);
        if(i==rear)
            break;
        i=(i+1)%n;
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

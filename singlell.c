#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next
}*newNode;
struct node *start=NULL;
struct node *createNode(int value)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;

};
void InsertBegin(int value)
{
    struct node* newNode=createNode(value);
    newNode->next=start;
    start=newNode;
}
void InsertEnd(int value)
{
    struct node* newNode=createNode(value);
    if(start==NULL)
    {
        start=newNode;
        return;
    }
    struct node *ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newNode;
}
void InsertPos(int value,int pos)
{
    if(pos<1)
    {
        printf("Invalid Position");
        return;
    }
     newNode=createNode(value);
     newNode->data=value;
    if(pos==1)
    {
        newNode->next=start;
        start=newNode;
        return;
    }

    struct node* ptr=start;
    for(int i=1;i<pos-1 && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("Position Out of Bound");
        free(newNode);
        return;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
}
void display()
{
    struct node *ptr=start;
    if(ptr==NULL)
    {
        printf("Empty__");

    }
    printf("List Elements ... \n");
    while(1)
    {
         printf("%d ->",ptr->data);
         ptr=ptr->next;
    }

}
void main(){
while(1)
{
    int k;
    printf("\n 1. Insert at beginning");
    printf("\n 2.Insert at End");
    printf("\n 3. Insertion at Position");
    printf("\n 4.Display");
    printf("\n 5.Exit");
    printf("\nEnter your choice");
    scanf("%d",&k);
    switch(k){
    case 1:printf("Enter value to insert");
    int j;
    scanf("%d",&j);
    InsertBegin(j);
    break;
    case 2:printf("Enter value to insert");
    int o;
    scanf("%d",&o);
    InsertEnd(o);
    break;
    case 3:printf("Enter value to insert and position:");
    int g,p;
    scanf("%d %d",&g,&p);
    InsertPos(g,p);
    break;
    case 4:display();
    break;
    case 5:printf("Program Exiting...");
    exit(0);
    default:printf("Invalid Choice..");
    }
}
}

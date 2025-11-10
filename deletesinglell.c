#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", value);
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }

    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}
void deleteAtPosition(int pos)
{
    if(head == NULL)
    {
        printf("Empty...");
        return;
    }
    if(pos == -1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    int i=1;
    while(temp != NULL && i<pos)
    {
        prev = temp;
        temp= temp->next;
        i++;
    }
    if(temp == NULL)
    {
        printf("Out Of Bound...");
        return;
    }
    prev->next = temp->next;
    printf("Deleted %d from position %d " , temp->data , pos);
    free(temp);
}
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("6. Deletion at Position\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                deleteAtBeginning();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            case 6:printf("Enter the position where you want to delete:");
            int pos;
            scanf("%d",&pos);
            deleteAtPosition(pos);
            break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


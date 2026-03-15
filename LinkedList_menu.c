#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node.
struct Node{
    int data;
    struct Node* next;
};

// Insert a node at the beginning.
void insertAtBeginning(struct Node** head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Inserted %d at the beginning\n", value);
}

// Insert a node at the end.
void insertAtEnd(struct Node** head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Inserted %d at the end\n", value);
}

// Delete the node at the beginning.
void deleteAtBeginning(struct Node** head){
    if(*head == NULL){
        printf("\nThe list is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);

    printf("\nDeleted node at the beginning\n");
}

// Delete the node at the end.
void deleteAtEnd(struct Node** head){
    if(*head == NULL){
        printf("\nThe list is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp->next == NULL){
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("\nDeleted node at the end\n");
}

// Display the linked list.
void displayList(struct Node* head){
    if (head == NULL){
        printf("\nThe list is empty\n");
        return;
    }
    printf("List:\n");

    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// The main function with menu.
int main(){
    struct Node* head = NULL;
    int choice, value;

    while(1){
        printf("\n=== THE MENU ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

        case 1:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            displayList(head);
            break;

        case 2:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            displayList(head);
            break;

        case 3:
            deleteAtBeginning(&head);
            displayList(head);
            break;

        case 4:
            deleteAtEnd(&head);
            displayList(head);
            break;

        case 5:
            printf("\nView ");
            displayList(head);
            break;

        case 6:
            printf("\nExiting program...\n");
            return 0;

        default:
            printf("\nInvalid choice. Choose only (1 - 6). Try again.\n");
        }
    }

    return 0;
}
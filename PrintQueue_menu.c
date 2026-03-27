#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Display queue
void display_Queue(){
    printf("\nCurrent Printer Queue:\n");

    if (front == -1){
        printf("[ EMPTY ]\n");
        return;
    }
    for (int i = front; i <= rear; i++){
        printf("[ %d pages ] ", queue[i]);
    }
    printf("\n");
}

// Enqueue (Request to Print)
void enqueue(int pages){
    if (rear == MAX - 1){
        printf("Queue is FULL!!\n");
        return;
    }
    if (front == -1){
        front = 0;
    }

    rear++;
    queue[rear] = pages;
    printf("Print request added: %d pages\n", pages);
}

// Dequeue (Perform Printing)
void dequeue() {
    if (front == -1){
        printf("Queue is EMPTY! Nothing to print.\n");
        return;
    }
    printf("Printing %d pages...\n", queue[front]);
    front++;

    // Reset if queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

int main() {
    int choice, pages;

    while (1){
        display_Queue();

        printf("\n=== Printer Queue Menu ===\n");
        printf("1. Request to Print\n");
        printf("2. Perform Printing\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter number of pages: ");
                scanf("%d", &pages);
                enqueue(pages);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice! Please choose only (1-3)\n");
        }
    }

    return 0;
}
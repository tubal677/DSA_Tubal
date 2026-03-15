#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push (add element).
void push(int value){
    if(top == MAX - 1){
        printf("\nStack Overflow! or Stack is full.\n");
    } else{
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Pop (remove top element).
void pop(){
    if(top == -1){
        printf("\nStack Underflow! or Stack is empty.\n");
    } else{
        printf("\n%d Removed from stack.\n", stack[top]);
        top--;
    }
}

// Peek (view top element).
void peek(){
    if(top == -1){
        printf("\nStack is empty.\n");
    } else{
        printf("\nTop element is: %d\n", stack[top]);
    }
}

// Display stack (show all elemens).
void display(){
    if(top == -1){
        printf("\nStack is empty.\n");
    } else{
        printf("\nView Stack:\n");
        for (int i = top; i >= 0; i--){
            printf("[%d]\n", stack[i]);
        }
    }
}

// The main function with menu.
int main(){
    int choice, value;

    while(1){
        printf("\n=== STACK MENU ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice. Choose only (1 - 5). Try Again.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Stack 
{
    struct Node* top;
};
void initStack(struct Stack* stack) 
{
    stack->top = NULL;
}
int isEmpty(struct Stack* stack) 
{
    return (stack->top == NULL);
}
void push(struct Stack* stack, int data) 
{
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("Pushed %d onto the stack.\n", data);
}
int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack is empty. Cannot pop from an empty stack.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}
void display(struct Stack* stack) 
{
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
int main() 
{
    struct Stack stack;
    initStack(&stack);

    int choice, data;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1) 
                {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice (1-4).\n");
        }
    }
    return 0;
}

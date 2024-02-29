// Austin Yelle
// Chpt5 PA

#include <stdio.h>
#include <stdlib.h>

// Variables
int *stack;
int top = -1;
int size;
int max_length;

// Stack gets resized
void stackResize() {
    size *= 2;
    stack = realloc(stack, size * sizeof(int));
}

// Item is pushed to stack
int push(int item) {
    if (top == max_length - 1) {
        printf("Cannot push, stack is full.\n");
        return 0;
    }
    if (top == size - 1) {
        stackResize();
    }
    if (top < size - 1) {
        stack[++top] = item;
        return 1;
    }
    return 0;
}

// Item popped from stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

// Check for empty stack
int isEmpty() {
    return top == -1;
}

// Value put at top of stack
int peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return -1;
}

// Output of stack from top to bottom
void printStack() {
    printf("The stack contents are the following:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    // Input on allocation size
    printf("Enter the allocation size for the stack: ");
    scanf("%d", &size);

    // Input for maximum stack length
    printf("Enter the maximum length of the stack: ");
    scanf("%d", &max_length);

    // Allocate memory for the stack
    stack = (int *)malloc(size * sizeof(int));

    
    printf("%s\n", push(1) ? "Item 1 was pushed successfully." : "Push unsuccessful.");

    printf("%s\n", push(2) ? "Item 2 was pushed successfully." : "Push unsuccessful.");

    printf("The top item on the stack is: %d\n", peek());

    printf("%s\n", push(3) ? "Item 3 was pushed successfully." : "Push unsuccessful.");

    printf("The length of the stack is: %d\n", top + 1);

    printf("The item popped from the stack was: %d\n", pop());

    printf("The top item on the stack is: %d\n", peek());

    printf("%s\n", push(4) ? "Item 4 was pushed successfully." : "Push unsuccessful.");

    printStack();

    printf("%s\n", push(5) ? "Item 5 was pushed successfully." : "Push unsuccessful.");

    printf("The item popped from the stack was: %d\n", pop());

    printf("%s\n", push(6) ? "Item 6 was pushed successfully." : "Push unsuccessful.");

    printStack();

    printf("The item popped from the stack was: %d\n", pop());

    printf("The stack is empty: %s\n", isEmpty() ? "True" : "False");

    printf("The item popped from the stack was: %d\n", pop());
    printf("The item popped from the stack was: %d\n", pop());
    printf("The item popped from the stack was: %d\n", pop());

    printf("The stack is empty: %s\n", isEmpty() ? "True" : "False");

    
    free(stack);

    return 0;
}
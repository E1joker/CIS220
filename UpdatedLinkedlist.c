//Austin Yelle
//Chpt4 PA

#include <stdio.h>
#include <stdlib.h>

// struct to hold the data and pointer of a node
struct node {
    int data;
    struct node *next;
};

// pointers to the head node
struct node *head = NULL;

// Function to perform the same list operation as the pseudocode found in section 4.2.5
void listPrepend(int data) {
    //create a link
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;

    // point it to old first node
    lk->next = head;

    //point first to new first node
    head = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.2.3
void listAppend(int data) {
    if (head == NULL) { // list is empty
        listPrepend(data);
    } else {
        //create a link
        struct node *lk = (struct node*) malloc(sizeof(struct node));
        lk->data = data;
        struct node *linkedlist = head;

        // point it to old first node
        while(linkedlist->next != NULL) {
            linkedlist = linkedlist->next;
        }
   
        //point first to new first node
        linkedlist->next = lk;
    }
}

// Function to perform the same list operation as the pseudocode found in section 4.3.1
void listInsertAfter(struct node *list, int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = list->next;
    list->next = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.4.1
// Function removes the node that is passed in, not the next node
void listRemoveNode(int key) {
    struct node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    // Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) return;

    // Remove the node
    prev->next = temp->next;
    free(temp);
}

// Function to perform the same list operation as the pseudocode found in section 4.5.1
// Function will return a 1 if found or 0 if not found
int listSearch(int key) {
    struct node *temp = head;
    while(temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

// Function to perform the same list operation as the pseudocode found in section 4.9.1
void listTraverse() {
    struct node *p = head;
    printf("\nThe list order is: ");

    //start from the beginning
    while(p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
}

// Function to sum the data values of all nodes in the linked list
int sumDataValues() {
    int sum = 0;
    struct node *current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int main() {
    // Append a node with a data value of 1-5 to the linked list
    listAppend(1);

    
    listAppend(2);

    
    listPrepend(3);

    
    listInsertAfter(head, 4);

   
    listAppend(5);

    // Insert a node with a data value of 6 after the node with a data value of 4 in the linked list
    struct node *current = head;
    while (current != NULL && current->data != 4) {
        current = current->next;
    }
    if (current != NULL) {
        listInsertAfter(current, 6);
    }

    // Insert a node with a data value of 7 after the node with a data value of 2 in the linked list
    current = head;
    while (current != NULL && current->data != 2) {
        current = current->next;
    }
    if (current != NULL) {
        listInsertAfter(current, 7);
    }

    // Display list
    listTraverse();

   
    listRemoveNode(3);

    // Remove the node after the node with a data value of 7
    current = head;
    while (current != NULL && current->data != 7) {
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        listRemoveNode(current->next->data);
    }

    // Display the updated list
    listTraverse();

    // Searches for the node with a value of 5 and outputs if it was found or not
    if (listSearch(5)) {
        printf("\nNode with data value 5 was found.\n");
    } else {
        printf("\nNode with data value 5 was not found.\n");
    }

    // Search for the node with a value of 2 and displays if it was found or not
    if (listSearch(2)) {
        printf("Node with data value 2 was found.\n");
    } else {
        printf("Node with data value 2 was not found.\n");
    }

    // Displays the sum 
    printf("The sum of the Linked list data values is: %d\n", sumDataValues());

    return 0;
}
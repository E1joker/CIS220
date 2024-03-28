// Austin Yelle
// Chpt7 PA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct BinarySearchTree {
    struct Node* root;
};

void initBST(struct BinarySearchTree* bst) {
    bst->root = NULL;
}

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void insert(struct BinarySearchTree* bst, struct Node* node) {
    if (bst->root == NULL) {
        bst->root = node;
        printf("Inserted node %d as the root node.\n", node->key);
    } else {
        struct Node* current = bst->root;
        struct Node* parent;
        while (true) {
            parent = current;
            if (node->key < current->key) {
                current = current->left;
                if (current == NULL) {
                    parent->left = node;
                    printf("Checking node %d for left child. Inserting node %d as left child of node %d.\n", parent->key, node->key, parent->key);
                    return;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = node;
                    printf("Checking node %d for right child. Inserting node %d as right child of node %d.\n", parent->key, node->key, parent->key);
                    return;
                }
            }
        }
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = removeNode(root->right, temp->key);
    }
    return root;
}

void print2DUtil(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);
    print2DUtil(root->left, space);
}

void print2D(struct Node* root) {
    print2DUtil(root, 0);
}

int main() {
    struct BinarySearchTree bst;
    initBST(&bst);

    // Nodes are inserted
    struct Node* node20 = createNode(20);
    insert(&bst, node20);
    
    struct Node* node35 = createNode(35);
    insert(&bst, node35);

    struct Node* node13 = createNode(13);
    insert(&bst, node13);

    struct Node* node6 = createNode(6);
    insert(&bst, node6);

    struct Node* node24 = createNode(24);
    insert(&bst, node24);

    struct Node* node18 = createNode(18);
    insert(&bst, node18);

    struct Node* node48 = createNode(48);
    insert(&bst, node48);

    struct Node* node1 = createNode(1);
    insert(&bst, node1);

    struct Node* node27 = createNode(27);
    insert(&bst, node27);

    // Output initial tree
    printf("Initial Binary Search Tree:\n");
    print2D(bst.root);

    // Remove nodes 18 and 48
    printf("\nRemoving nodes 18 and 48:\n");
    bst.root = removeNode(bst.root, 18);
    bst.root = removeNode(bst.root, 48);

    // Output tree after removal
    printf("\nBinary Search Tree after removing nodes 18 and 48:\n");
    print2D(bst.root);

    // Insert nodes 16 and 45
    printf("\nInserting nodes 16 and 45:\n");
    struct Node* node16 = createNode(16);
    insert(&bst, node16);

    struct Node* node45 = createNode(45);
    insert(&bst, node45);

    // Output tree after insertion
    printf("\nBinary Search Tree after inserting nodes 16 and 45:\n");
    print2D(bst.root);

    // Remove nodes 6 and 24
    printf("\nRemoving nodes 6 and 24:\n");
    bst.root = removeNode(bst.root, 6);
    bst.root = removeNode(bst.root, 24);

    // Output tree after removal
    printf("\nBinary Search Tree after removing nodes 6 and 24:\n");
    print2D(bst.root);

    // Remove the node 20 and attempt to remove node 38 
    printf("\nRemoving node 20 and attempting to remove node 38:\n");
    bst.root = removeNode(bst.root, 20);
    removeNode(bst.root, 38); // Not in tree

    // Print final tree
    printf("\nBinary Search Tree after removing node 20 and attempting to remove node 38:\n");
    print2D(bst.root);

    
    free(node20);
    free(node35);
    free(node13);
    free(node6);
    free(node24);
    free(node18);
    free(node48);
    free(node1);
    free(node27);
    free(node16);
    free(node45);

    return 0;
}
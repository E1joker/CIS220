// Austin Yelle
// Chpt6 PA
#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 16
#define EMPTY -1
#define REMOVED -2
#define C1 1
#define C2 1

int hash(int key);
bool hashInsert(int item);
bool hashRemove(int item);
int hashSearch(int item);
void displayHashTable();

int hashTable[TABLE_SIZE];

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    // Insert items into the hash table
    printf("Item 32: %s\n", hashInsert(32) ? "Inserted successfully" : "Insert failed");
    printf("Item 63: %s\n", hashInsert(63) ? "Inserted successfully" : "Insert failed");
    printf("Item 16: %s\n", hashInsert(16) ? "Inserted successfully" : "Insert failed");
    printf("Item 3: %s\n", hashInsert(3) ? "Inserted successfully" : "Insert failed");
    printf("Item 23: %s\n", hashInsert(23) ? "Inserted successfully" : "Insert failed");
    printf("Item 11: %s\n", hashInsert(11) ? "Inserted successfully" : "Insert failed");
    printf("Item 64: %s\n", hashInsert(64) ? "Inserted successfully" : "Insert failed");
    printf("Item 99: %s\n", hashInsert(99) ? "Inserted successfully" : "Insert failed");
    printf("Item 42: %s\n", hashInsert(42) ? "Inserted successfully" : "Insert failed");
    printf("Item 49: %s\n", hashInsert(49) ? "Inserted successfully" : "Insert failed");
    printf("Item 48: %s\n", hashInsert(48) ? "Inserted successfully" : "Insert failed");
    printf("Item 21: %s\n", hashInsert(21) ? "Inserted successfully" : "Insert failed");

    // Output the hash table
    printf("\nThe hash table contents are:\n");
    displayHashTable();

    printf("Item 32: %s\n", hashRemove(32) ? "was removed successfully" : "Item not found");
    printf("Item 11: %s\n", hashRemove(11) ? "was removed successfully" : "Item not found");
    int searchResult64 = hashSearch(64);
    printf("Item 64: %s, in bucket %d\n", searchResult64 != -9 ? "found" : "not found", searchResult64);
    printf("Item 9: %s\n", hashInsert(9) ? "was inserted successfully" : "failed to insert");
    printf("Item 48: %s\n", hashSearch(48) != -9 ? "was found in bucket 12" : "was not found");
    printf("Item 32: %s\n", hashSearch(32) != -9 ? "was found in bucket 0" : "was not found");
    printf("Item 64: %s\n", hashRemove(64) ? "was removed successfully" : "was not found");
    printf("Item 99: %s\n", hashRemove(99) ? "was removed successfully" : "was not found");

    // Output the hash table
    printf("\nThe hash table contents are:\n");
    displayHashTable();

    return 0;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

bool hashInsert(int item) {
    int index = hash(item);
    int originalIndex = index;
    int i = 1;

    while (hashTable[index] != EMPTY && hashTable[index] != REMOVED) {
        index = (originalIndex + C1 * i + C2 * i * i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) // Table is full
            return false;
    }

    hashTable[index] = item;
    return true;
}

bool hashRemove(int item) {
    int index = hashSearch(item);
    if (index == -9)
        return false;

    hashTable[index] = REMOVED;
    return true;
}

int hashSearch(int item) {
    int index = hash(item);
    int originalIndex = index;
    int i = 1;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == item)
            return index;

        index = (originalIndex + C1 * i + C2 * i * i) % TABLE_SIZE;
        i++;
        if (index == originalIndex || hashTable[index] == REMOVED) // Item not found
            return -9;
    }

    return -9; // Item not found
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("HashTable[%d]: ", i);
        if (hashTable[i] == EMPTY)
            printf("-1\n");
        else if (hashTable[i] == REMOVED)
            printf("-2\n");
        else
            printf("%d\n", hashTable[i]);
    }
}
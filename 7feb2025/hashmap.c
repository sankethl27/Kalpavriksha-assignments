
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1000  

typedef struct HashMap {
    char name[200];
    long long number;
} HashMap;

typedef struct linkedList {
    HashMap map;
    struct linkedList *next;
} node;

node *hashTable[HASH_TABLE_SIZE];

unsigned int hashFunction(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_TABLE_SIZE;
}

node *createNode(char name[], long long number) {
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->map.name, name);
    newNode->map.number = number;
    newNode->next = NULL;
    return newNode;
}

void add(char name[], long long number) {
    unsigned int index = hashFunction(name);
    node *temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->map.name, name) == 0) {
            temp->map.number = number;
            printf("Success\n");
            return;
        }
        temp = temp->next;
    }

    node *newNode = createNode(name, number);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Success\n");
}

int search(char name[]) {
    unsigned int index = hashFunction(name);
    node *temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->map.name, name) == 0) {
            printf("%lld\n", temp->map.number);
            return 1;
        }
        temp = temp->next;
    }
    printf("Not Found\n");
    return 0;
}

int delete(char name[]) {
    unsigned int index = hashFunction(name);
    node *current = hashTable[index];
    node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->map.name, name) == 0) {
            if (previous == NULL) {
                hashTable[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Success\n");
            return 1;
        }
        previous = current;
        current = current->next;
    }

    printf("Not Found\n");
    return 0;
}

int main() {
    memset(hashTable, 0, sizeof(hashTable));  // Fix: Initialize hash table

    int n;
    scanf("%d", &n);

    char input[300], operation[200], name[200];
    long long number;

    for (int i = 0; i < n; i++) {
        fgets(input, 300, stdin);
        input[strcspn(input, "\n")] = '\0';

        sscanf(input, "%[^(](", operation);

        if (strcmp(operation, "add") == 0) {
            sscanf(input, "%*[^(\"](\"%[^\"]\", %lld)", name, &number);
            add(name, number);
        } else if (strcmp(operation, "search") == 0) {
            sscanf(input, "%*[^(\"](\"%[^\"]\")", name);
            search(name);
        } else {
            sscanf(input, "%*[^(\"](\"%[^\"]\")", name);
            delete(name);
        }
    }
    return 0;
}

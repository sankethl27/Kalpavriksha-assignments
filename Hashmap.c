#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


enum MENU_OPTIONS{
    ADD = 1, FIND, REMOVE, SHOW, QUIT
};

typedef struct HashNode{
    int key;
    int data;
    struct HashNode* link;
} HashNode;

typedef struct HashMap{
    HashNode* table[SIZE];
} HashMap;

void initializeMap(HashMap* map){
    for(int i = 0; i < SIZE; i++){
        map->table[i] = NULL;
    }
}

HashNode* createNode(int key, int data){
    HashNode* newNode = malloc(sizeof(HashNode));
    newNode->link = NULL;
    newNode->key = key;
    newNode->data = data;
    return newNode;
}

int hashFunction(int key){
    return key % SIZE;
}

void insertKey(HashMap* map, int key, int data){
    int index = hashFunction(key);
    HashNode* newNode = createNode(key, data);
    if(map->table[index] == NULL){
        map->table[index] = newNode;
    }
    else{
        newNode->link = map->table[index];
        map->table[index] = newNode;
    }
}

void searchKey(HashMap map, int key){
    int index = hashFunction(key);
    HashNode* temp = map.table[index];
    while(temp != NULL){
        if(temp->key == key){
            printf("Data: %d\n", temp->data);
            return;
        }
        temp = temp->link;
    }
    printf("Key %d not found\n", key);
}

void deleteKey(HashMap* map, int key){
    int index = hashFunction(key);
    HashNode* temp = map->table[index], *prev = NULL;
    while(temp != NULL){
        if(temp->key == key){
            if(prev == NULL){
                map->table[index] = temp->link;
            }
            else{
                prev->link = temp->link;
            }
            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->link;
    }
    printf("Key %d not found\n", key);
}

void displayMap(HashMap map){
    printf("Hash Table:\n");
    for(int i = 0; i < SIZE; i++){
        if(map.table[i] != NULL){
            printf("Index %d: ", i);
            HashNode* temp = map.table[i];
            while(temp->link != NULL){
                printf("(%d, %d) -> ", temp->key, temp->data);
                temp = temp->link;
            }
            printf("(%d, %d)\n", temp->key, temp->data);
        }
    }
}

int main(){
    HashMap map;
    int key, data, option = 0;
    
    initializeMap(&map);
    
    while(option != QUIT){
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option){
            case ADD:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                insertKey(&map, key, data);
                break;
            case FIND:
                printf("Enter key: ");
                scanf("%d", &key);
                searchKey(map, key);
                break;
            case REMOVE:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(&map, key);
                break;
            case SHOW:
                displayMap(map);
                break;
            case QUIT:
                printf("Exiting program.\n");
                return 0;
        }
    }
    return 0;
}

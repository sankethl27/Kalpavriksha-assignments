#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10000
typedef struct HashMap
{
    int key;
    int index;
    struct HashMap *next;
}Hashmap;

Hashmap *map[MAX_SIZE];

void intialize()
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
        map[i] = NULL;
    }
}

int hash(int key)
{
    key = abs(key);
    return key % MAX_SIZE;
}

Hashmap *createNode(int key,int index)
{
    Hashmap *newNode = malloc(sizeof(Hashmap));
    newNode->key = key;
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

int find(int key)
{
    int index = hash(key);
    Hashmap *start = map[index];
    while(start != NULL)
    {
        if(start->key == key)
        {
            return start->index;
        }
        start = start->next;
    }
    return -1;
}

void insert(int key,int index)
{
    int hashindex = hash(key);
    Hashmap *start = map[hashindex];
    Hashmap *newNode = createNode(key,index);
    newNode->next = start;
    map[hashindex] = newNode;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    intialize();
    int *result = malloc(2*sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        int rem = target - nums[i];
        int index = find(rem);
        if(index == -1)
        {
            insert(nums[i],i);
        }
        else
        {
            result[0] = index;
            result[1] = i;
            break;
        } 
    }
    *returnSize = 2;
    return result;       

}

int main()
{
    int n;
    int target;
    printf("Enter size of the array\n");
    scanf("%d",&n);
    int *array = malloc(n * sizeof(int));
    printf("Enter elements of the array\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",array + i);
    }
    printf("Enter target\n");
    scanf("%d",&target);
    int resultSize;
    int *result = twoSum(array,n,target,&resultSize);
    printf("Pairs are are : \n");
    printf("[");
    int isfirst = 1;
    for(int i = 0; i < resultSize; i++)
    {
        if(!isfirst) printf(", ");
        printf("%d" , *(result + i));
        isfirst = 0;
    }
    printf("]\n");
    return 0;
}
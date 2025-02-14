int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int size = 0;
    int maxi = -1;
    int *freq = calloc(numsSize+1,sizeof(int));
    int *result = malloc((numsSize + 1) * sizeof(int));

    for(int i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;
    }
   
    for(int i = 0; i <= numsSize; i++)
    {
        if(freq[i] > 1)
        {
            result[size++] = i;
        } 
    }

    result = realloc(result,size*sizeof(int));
    *returnSize = size;
    return result;
}
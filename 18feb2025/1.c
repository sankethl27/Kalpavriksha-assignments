//Find the Smallest Subarray with All Occurrences of the Most Frequent Element
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int left[10] = {0};
    int count[10] = {0};
    int size = 7;
    int startIndex = 0;
    int maxFreq = 0;
    int arr[7] = {1, 2, 2, 3, 1, 4, 2};
    int len = 0;
    for(int i = 0; i < size; i++)
    {
        int num = arr[i];
        if(count[num] == 0)
        {
            left[num] = i;
            count[num] = 1;
        } 
        else count[num]++;
        if(count[num] > maxFreq)
        {
            maxFreq = count[num];
            startIndex = left[num];
            len = i - startIndex + 1;
        }
        else if(count[num] == maxFreq && len > left[num] - i + 1)
        {
            startIndex = left[num];
            len = i - startIndex + 1;
        }
    }
    printf("%d %d\n",startIndex,len);
    for(int i = startIndex; i <= len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
#include<stdio.h>
#include<stdio.h>


void mergeSort(int *arr, int low , int high)
{
    if(low >= high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    int leftSize = mid-low+1;
    int rightSize = high - mid;
    int left[leftSize];
    int right[rightSize];
    
    for(int i = 0; i < leftSize; i++)
    {
        left[i] = arr[i + low];
    }

    for(int i = 0; i < rightSize; i++)
    {
        right[i] = arr[i+mid+1];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while(i < leftSize && j < rightSize)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < leftSize)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < rightSize)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

}
void uniqueElements(int arr[] , int n)
{
    printf("%d ",arr[0]);
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[i-1])
        {
            printf("%d ",arr[i]);
        }
    }
}
int main()
{
    int n = 6;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted Elememts are : ");
    for(int i = 0; i < n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Unique Elements are : ");
    uniqueElements(arr,n);
}
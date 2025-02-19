#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

char* minWindow(char* s, char* t) {
    int hash[256];
    int count = 0;
    int size = strlen(t);
    int len = INT_MAX;
    int start = 0;
    int right = 0;
    int left = 0;
    int sizeS = strlen(s);
    memset(hash,0,256 * sizeof(int));
    for(int k = 0; k < strlen(t); k++) hash[t[k]]++;
    while(right < sizeS)
    {
        if(hash[s[right]] > 0) count++;
        hash[s[right]] -= 1;
        while(count == size)
        {
            if(right - left + 1 < len)
            {
                len = right - left + 1;
                start = left;
            }
            hash[s[left]] += 1;
            if(hash[s[left]] > 0) count--;
            left++;
        }
        right++;
    }
    if(len == INT_MAX)
    {
        return "\0";
    } 
    char *result = malloc((len+1)*sizeof(char));
    int it= 0;
   
    for(int i = start; i < start + len; i++)
    {
        result[it++] = s[i];
    }
    result[it] = '\0';
    return result;
}
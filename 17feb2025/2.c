// Longest Substring with Exactly K Distinct Characters

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int  a , int b)
{
    if(a < b) return b;
    return a;
}

int  subStringWithKDistinctCharacters(char s[] , int k)
{
    int freq[256] = {0};
    int len = strlen(s);

    int left = 0;
    int right = 0;
    int ans = 0;
    int unique = 0;
    while(right < len)
    {
        if(freq[s[right]] == 0) unique++;
        freq[s[right]]++;
        while(unique > k)
        {
            freq[s[left]]--;
            if(freq[s[left]] == 0)
            {
                unique--;
            }
            left++;
        }
        if(unique == k) ans = max(ans,right-left+1);
        right++;
    }
    return ans;
}
int main()
{
    char s[] = "abcabcbb";
    int result;
    result =   subStringWithKDistinctCharacters(s,2);
    printf("%d\n",result);
    return 0;
}
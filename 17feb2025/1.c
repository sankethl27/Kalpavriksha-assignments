// Longest Substring Without Repeating Characters
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int  a , int b)
{
    if(a < b) return b;
    return a;
}
int lengthOfLongestSubstring(char s[]) {
    int freq[256] = {0};
    int r = 0;
    int ans = 0;
    int l = 0;
    int maxUnique;
    
    while(s[r] != '\0')
    {
        freq[s[r]]++;
        while(freq[s[r]] > 1)
        {
            freq[s[l]]--;
            l++;
        }
        ans = max(ans,r-l+1);
        r++;
    }
    return ans;
}
int main()
{
    char s[] = "abcabcbb";
    int result;
    result =  lengthOfLongestSubstring(s);
    printf("%d\n",result);
    return 0;
}
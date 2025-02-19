#include<bits\stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    map <char,int> mpp;
    int right = 0;
    int left = 0;
    int ans = 0;
    int count = 0;
    while(right < left)
    {
        mpp[str[left]]++;
        count++;
        while(mpp.size() > k)
        {
            mpp[str[left]]--;
            count--;
            if(mpp[str[left]] == 0) mpp.erase(str[left]);
        }
        ans = max(ans,count);
        right++;
    }
    return ans;
}

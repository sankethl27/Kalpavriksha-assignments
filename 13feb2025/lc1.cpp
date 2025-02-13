#include<bits\stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long,vector<long long >,greater<long long>> pq;
            int count = 0;
            for(int i = 0;i < nums.size(); i++)
            {
                if(nums[i] < k)
                {
                    pq.push(nums[i]);
                }
            }
            if(pq.size() == 0) return 0;
            while(pq.top() < k)
            {
                if(pq.size() == 1)
                {
                    return count + 1;
                }
                long long mini = pq.top();
                pq.pop();
                long long maxi = pq.top();
                pq.pop();
                long long result = mini*2 + maxi;
                pq.push(result);
                count++;
            }
            return count;
        }
    };
int main()
{
    Solution sol;
    vector<int> nums = {69,89,57,31,84,97,50,38,91,86};
    int k = 91;
    cout<<sol.minOperations(nums,k);
}

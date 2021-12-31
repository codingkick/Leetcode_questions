class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,0),r(n,0);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1] == 0)
                l[i] = 0;
            else
                l[i] = l[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1] == 0)
                r[i] = 0;
            else
                r[i] = r[i+1]+1;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,l[i]+r[i]);
        }
        return ans;
    }
};
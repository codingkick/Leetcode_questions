class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        vector<int> dp(n,0);
        dp[0] = nums[0];
        if(n==1)
            return dp[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        return dp[n-1];
    }
};
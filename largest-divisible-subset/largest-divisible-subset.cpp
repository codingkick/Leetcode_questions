class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,{-1,1});
        sort(nums.begin(),nums.end());
        dp[0] = {-1,1};
        int ans = 1;
        int ind = 0;
        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                if(nums[j]%nums[i] == 0)
                {
                    if(dp[j][1] < 1 + dp[i][1])
                    {
                        dp[j][1] = 1 + dp[i][1];
                        dp[j][0] = i;
                    }
                    if(ans<dp[j][1])
                    {
                        ans = dp[j][1];
                        ind = j;
                    }
                }
            }
        }
        // cout<<dp[n-1][1]<<" "<<dp[n-1][0]<<"\n";
        // cout<<dp[4][1]<<" "<<dp[4][0]<<"\n";
        // cout<<dp[1][1]<<" "<<dp[1][0]<<"\n";
        vector<int> res;
        int x = ind;
        while(x>=0)
        {
            res.push_back(nums[x]);
            x = dp[x][0];
        }
        return res;
    }
};
class Solution {
public:
    int func(vector<int> &prices,int ind,vector<int> &dp)
    {
        if(dp[ind] != -1)
            return dp[ind];
        int n = prices.size();
        int v1 = func(prices,ind-1,dp);
        int val = INT_MIN;
        for(int i=ind-1;i>=0;i--)
        {
            if(i == 0 || i == 1)
            {
                val = max(val,prices[ind] - prices[i]);
            }
            else
            {
                val = max(val,prices[ind] - prices[i] + func(prices,i-2,dp));
            }
        }
        dp[ind] = max(v1,val);
        return dp[ind];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        return func(prices,n-1,dp);
    }
};
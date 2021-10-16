class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        int min_val = prices[0];
        for(int i=1;i<n;i++)
        {
            min_val = min(min_val,prices[i]);
            dp[i] = prices[i] - min_val;
        }
        int max_val = prices[n-1];
        int temp = 0;
        for(int i=n-2;i>=0;i--)
        {
            max_val = max(max_val,prices[i]);
            temp = max(max_val-prices[i],temp);
            dp[i] += temp;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        return ans;
    }
};
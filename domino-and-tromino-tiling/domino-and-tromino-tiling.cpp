class Solution {
public:
    int numTilings(int n) {
        vector<long long int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        int mod = 1000000007;
        for(int i=2;i<=n;i++)
        {
            if(i<=2)
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
            else if(i<=3)
            {
                dp[i] = (dp[i-1]%mod + dp[i-2]%mod + (2*dp[i-3])%mod)%mod;
            }
            else
            {
                dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
                // cout<<dp[i]<<" : ";
                for(int j=4;j<=i;)
                {
                    dp[i] = (dp[i]%mod + (2*dp[i-j])%mod)%mod;
                    j += 2;
                }
                for(int j=3;j<=i;)
                {
                    dp[i] = (dp[i]%mod + (2*dp[i-j])%mod)%mod;
                    j += 2;
                }
                // cout<<dp[i]<<"\n";
            }
        }
        return (int)dp[n]%mod;
    }
};
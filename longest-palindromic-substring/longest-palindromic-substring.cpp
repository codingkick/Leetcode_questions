class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<int> vec(n,0);
        vector<vector<int>> dp(n+1,vec);
        for(int i=0;i<n;i++)
            dp[1][i] = 1;
        int max_len = 1,ind = 0;
        for(int i=1;i<n;i++)
        {
            if(s[i] == s[i-1])
                dp[2][i] = 1;
            if(dp[2][i] == 1 && 2>max_len)
            {
                ind = i;
                max_len = 2;
            }
        }
        for(int i=3;i<=n;i++)
        {
            for(int j=i-1;j<n;j++)
            {
                if(s[j] == s[j-i+1])
                {
                    dp[i][j] = dp[i-2][j-1];
                    if(dp[i][j] == 1 && i>max_len)
                    {
                        ind = j;
                        max_len = i;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        string ans = "";
        for(int i=ind-max_len+1;i<=ind;i++)
            ans += s[i];
        return ans;
    }
};
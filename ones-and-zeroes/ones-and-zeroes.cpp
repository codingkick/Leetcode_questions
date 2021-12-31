class Solution {
public:
    int func(vector<vector<int>> &dp,int n,int m,int ind,vector<vector<vector<int>>> &mem)
    {
        // cout<<n<<" "<<m<<" "<<ind<<"\n";
        if(n<0)
            return INT_MIN;
        if(m<0)
            return INT_MIN;
        if(ind<0)
            return 0;
        if(mem[ind][n][m]!=-1)
            return mem[ind][n][m];
        else
        {
            // if dp[ind] is taken
            int v1 = func(dp,n-dp[ind][1],m-dp[ind][0],ind-1,mem);
            // if dp[ind] is not taken
            int v2 = func(dp,n,m,ind-1,mem);
            mem[ind][n][m] = max(v1+1,v2);
            return mem[ind][n][m];
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<int> vec(m+1,-1);
        vector<vector<int>> vec2(n+1,vec);
        vector<vector<vector<int>>> mem(s,vec2);
        vector<vector<int>> dp(s,{0,0});
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<strs[i].length();j++)
            {
                if(strs[i][j] == '0')
                    dp[i][0] += 1;
                else
                    dp[i][1] += 1;
            }
        }
        // return 0;
        return func(dp,n,m,s-1,mem);
    }
};
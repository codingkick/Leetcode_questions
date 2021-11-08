class Solution {
public:
    int func(int l,int r,vector<vector<int>> &mem)
    {
        if(l>=r)
            return 1;
        if(mem[l][r]!= -1)
            return mem[l][r];
        else
        {
            int res = 0;
            for(int i=l;i<=r;i++)
            {
                int v1 = func(l,i-1,mem);
                int v2 = func(i+1,r,mem);
                res += (v1*v2);
            }
            mem[l][r] = res;
            return res;
        }
    }
    int numTrees(int n) {
        int ans = 0;
        vector<int> vec(n+1,-1);
        vector<vector<int>> mem(n+1,vec);
        for(int i=1;i<=n;i++)
        {
            int v1 = func(1,i-1,mem);
            int v2 = func(i+1,n,mem);
            ans += (v1*v2);
        }
        return ans;
    }
};
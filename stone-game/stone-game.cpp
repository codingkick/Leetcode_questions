class Solution {
public:
    int f(int l,int r,vector<int> &p,vector<vector<int>> &mem)
    {
        if(l>r)
            return 0;
        if(mem[l][r] != -1)
            return mem[l][r];
        else
        {
            int v1 = f(l+2,r,p,mem);
            int v2 = f(l+1,r-1,p,mem);
            int v3 = f(l,r-2,p,mem);
            mem[l][r] = max(p[l] + min(v1,v2),p[r] + min(v2,v3));
            return mem[l][r];
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> vec(n,-1);
        vector<vector<int>> mem(n,vec);
        int total = 0;
        for(int i=0;i<n;i++)
            total += piles[i];
        for(int i=0;i<n;i++)
        {
            mem[i][i] = piles[i];
            if(i<n-1)
            {
                mem[i][i+1] = max(piles[i],piles[i+1]);
            }
        }
        int val = f(0,n-1,piles,mem);
        if(val > total-val)
            return true;
        else
            return false;
    }
};
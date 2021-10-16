class Solution {
public:
    int func(int ind,vector<int> &p,vector<vector<int>> &mem,int opt)
    {
        int n = p.size();
        if(ind>=n)
            return 0;
        if(mem[opt][ind] != -1)
            return mem[opt][ind];
        int val;
        if(opt == 0)
            val = INT_MIN;
        else
            val = INT_MAX;
        int sum = 0;
        for(int i=ind;i<min(n,ind+3);i++)
        {
            sum += p[i];
            int temp = func(i+1,p,mem,opt^1);
            if(opt == 0)
            {
                val = max(val,temp + sum);
            }
            else
            {
                val = min(val,temp);
            }
        }
        mem[opt][ind] = val;
        return mem[opt][ind];
    }
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        vector<int> mem2(n,-1);
        vector<vector<int>> mem(2,mem2);
        int total = 0;
        for(int i=0;i<n;i++)
            total += piles[i];
        int ans = func(0,piles,mem,0);
        if(ans>total-ans)
            return "Alice";
        else if(ans == total - ans)
            return "Tie";
        else
            return "Bob";
    }
};
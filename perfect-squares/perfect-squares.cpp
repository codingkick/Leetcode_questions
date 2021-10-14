class Solution {
public:
    int func(int n,int s,vector<int> &p,vector<vector<int>> &mem)
    {
        if(n == 0)
            return 0;
        if(s == 0)
            return 10001;
        if(mem[n][s] != -1)
            return mem[n][s];
        else
        {
            if(p[s-1] <= n)
            {
                int v1 = 1 + func(n-p[s-1],s,p,mem);
                int v2 = func(n,s-1,p,mem);
                mem[n][s] = min(v1,v2);
            }
            else
            {
                mem[n][s] = func(n,s-1,p,mem);
            }
            return mem[n][s];
        }
    }
    int numSquares(int n) {
        vector<int> p;
        for(int i=1;i<=sqrt(n);i++)
        {
            p.push_back(i*i);
        }
        int s = p.size();
        vector<int> vec(s+1,-1);
        vector<vector<int>> mem(n+1,vec);
        int val = func(n,s,p,mem);
        return val;
    }
};
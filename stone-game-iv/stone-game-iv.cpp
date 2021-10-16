class Solution {
public:
    int func(int n,vector<vector<int>> &mem,int opt)
    {
        if(n == 0)
            return 0;
        if(mem[opt][n] != -1)
            return mem[opt][n];
        for(int i=1;i<=sqrt(n);i++)
        {
            int temp = func(n-i*i,mem,opt^1);
            if(opt == 0)
            {
                if(temp == 0)
                {
                    mem[opt][n] = 1;
                    return 1;
                }
            }
            else
            {
                if(temp == 0)
                {
                    mem[opt][n] = 1;
                    return 1;
                }
            }
        }
        mem[opt][n] = 0;
        if(opt == 0)
            return 0;
        else
            return 0;
    }
    bool winnerSquareGame(int n) {
        vector<int> mem2(n+1,-1);
        vector<vector<int>> mem(2,mem2);
        int ans = func(n,mem,0);
        if(ans == 0)
            return false;
        else
            return true;
    }
};
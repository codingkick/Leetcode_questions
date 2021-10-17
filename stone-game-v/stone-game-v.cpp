class Solution {
public:
    int func(int i,int j,vector<vector<int>> &mem,vector<int> &p)
    {
        if(i == j)
            return 0;
        if(mem[i][j] != -1)
            return mem[i][j];
        else
        {
            int total = 0;
            for(int k=i;k<=j;k++)
                total += p[k];
            int sum = 0;
            int val = INT_MIN;
            for(int k=i;k<j;k++)
            {
                sum += p[k];
                int temp;
                if(sum>total-sum)
                {
                    temp = (total-sum) + func(k+1,j,mem,p);
                }
                else if(sum < total - sum)
                {
                    temp = sum + func(i,k,mem,p);
                }
                else
                {
                    int temp1 = func(i,k,mem,p);
                    int temp2 = func(k+1,j,mem,p);
                    temp = sum + max(temp1,temp2);
                }
                val = max(val,temp);
                mem[i][j] = val;
            }
            return mem[i][j];
        }
    }
    int stoneGameV(vector<int>& piles) {
        int n = piles.size();
        vector<int> vec(n,-1);
        vector<vector<int>> mem(n,vec);
        return func(0,n-1,mem,piles);
    }
};
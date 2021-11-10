class Solution {
public:
    // int func(int i,vector<int> &mem,vector<int> &prices)
    // {
    //     if(i<=0)
    //         return 0;
    //     if(mem[i] != -1)
    //         return mem[i];
    //     else
    //     {
    //         int sell = 0;
    //         for(int j=i-1;j>0;j--)
    //         {
    //             sell = max(sell,func(j,mem,prices) + prices[i-1] - prices[j-1]);
    //         }
    //         int not_sell = func(i-1,mem,prices);
    //         mem[i] = max(sell,not_sell);
    //         return mem[i];
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mem(n,0);
        mem[0] = 0;
        int val = INT_MIN;
        for(int i=1;i<n;i++)
        {
            val = max(val,mem[i-1] - prices[i-1]);
            mem[i] = max(val+prices[i],mem[i-1]);
        }
        // return func(n,mem,prices);
        return mem[n-1];
    }
};
class Solution {
public:
    int f(int ind,vector<int> &p,vector<vector<vector<int>>> &mem,int opt,int m)
    {
        int n = p.size();
        if(ind>=n)
            return 0;
        if(mem[opt][m][ind] != -1)
            return mem[opt][m][ind];
        int sum = 0;
        int val;
        if(opt == 0)
            val = INT_MIN;
        else
            val = INT_MAX;
        for(int i=ind;i<min(n,ind+2*m);i++)
        {
            sum += p[i];
            int temp = f(i+1,p,mem,opt^1,max(m,i-ind+1));
            if(opt == 0)
            {
                val = max(val,temp+sum);
            }
            else
            {
                val = min(val,temp);
            }
            // if(ind == 0)
            // {
            //     cout<<temp<<" "<<sum<<"<-s ";
            // }
        }
        // cout<<"for ind : "<<ind<<" and opt: "<<opt<<" val : "<<val<<"\n";
        mem[opt][m][ind] = val;
        return val;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> vec(n,-1);
        vector<vector<int>> mem2(51,vec);
        vector<vector<vector<int>>> mem(2,mem2);
        int ans = f(0,piles,mem,0,1);
        return ans;
    }
};
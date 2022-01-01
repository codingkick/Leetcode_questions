class Solution {
public:
    int func(vector<vector<int>> &mem,int l,int r,vector<int> &a)
    {
        if(l>r)
            return 0;
        if(mem[l][r]!=-1)
            return mem[l][r];
        else
        {
            int val = 0;
            for(int i=l;i<=r;i++)
            {
                int v1 = func(mem,l,i-1,a);
                int v2 = a[l-1]*a[i]*a[r+1];
                int v3 = func(mem,i+1,r,a);
                int curr = v1+v2+v3;
                val = max(val,curr);
            }
            mem[l][r] = val;
            return mem[l][r];
        }
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        a.push_back(1);
        for(int i=0;i<n;i++)
            a.push_back(nums[i]);
        a.push_back(1);
        n = a.size();
        vector<int> vec(n,-1);
        vector<vector<int>> mem(n,vec);
        
        return func(mem,1,n-2,a);
    }
};
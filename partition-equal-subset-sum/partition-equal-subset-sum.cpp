class Solution {
public:
    int func(int n,int s,vector<vector<int>> &mem,vector<int> &nums)
    {
        if(n == 0)
        {
            if(s == 0)
                return 1;
            else
                return 0;
        }
        if(s == 0)
            return 1;
        if(mem[n][s] != -1)
            return mem[n][s];
        else
        {
            int v1 = 0,v2 = 0;
            if(s-nums[n-1]>=0)
                v1 = func(n-1,s-nums[n-1],mem,nums);
            v2 = func(n-1,s,mem,nums);
            mem[n][s] = max(v1,v2);
            return mem[n][s];
        }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        if(sum%2 != 0)
            return false;
        vector<int> vec(sum/2+1,-1);
        vector<vector<int>> mem(n+1,vec);
        int ans = func(n,sum/2,mem,nums);
        if(ans == 1)
            return true;
        else
            return false;
    }
};
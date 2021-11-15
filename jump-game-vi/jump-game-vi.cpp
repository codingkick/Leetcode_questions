class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int i=1;i<n;i++)
        {
            int temp = dq.front(); 
            if(i-temp>k)
            {
                dq.pop_front();
                temp = dq.front();
            }
            dp[i] = nums[i] + dp[temp];
            while(dq.size()!=0)
            {
                int t = dq.back();
                if(dp[t]<dp[i])
                    dq.pop_back();
                else
                    break;
            }
            dq.push_back(i);
        }
        return dp[n-1];
    }
};
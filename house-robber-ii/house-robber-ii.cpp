class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        //two case : either looting 1st house or not at all.
        // case1 :
        vector<vector<int>> dp1(n,{0,0}),dp2(n,{0,0});
        dp1[0][0] = 0;
        dp1[0][1] = nums[0];
        int ans1 = nums[0];
        for(int i=1;i<n-1;i++)
        {
            dp1[i][0] = max(dp1[i-1][0],dp1[i-1][1]);
            dp1[i][1] = dp1[i-1][0] + nums[i];
            ans1 = max({ans1,dp1[i][0],dp1[i][1]});
        }
        dp2[1][0] = 0;
        dp2[1][1] = nums[1];
        int ans2 = nums[1];
        for(int i=2;i<n;i++)
        {
            dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1]);
            dp2[i][1] = dp2[i-1][0] + nums[i];
            ans2 = max({ans2,dp2[i][0],dp2[i][1]});
        }
        return max({ans1,ans2});
    }
};
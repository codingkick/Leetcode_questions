class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int ans = max_sum;
        for(int i=1;i<n;i++)
        {
            max_sum = max(max_sum+nums[i],nums[i]);
            ans = max(ans,max_sum);
        }
        return ans;
    }
};
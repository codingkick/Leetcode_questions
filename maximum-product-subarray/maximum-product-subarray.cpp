class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++)
        {
            int temp = maxi;
            maxi = max(maxi*nums[i],max(mini*nums[i],nums[i]));
            mini = min(temp*nums[i],min(mini*nums[i],nums[i]));
            ans = max(ans,maxi);
        }
        return ans;
    }
};
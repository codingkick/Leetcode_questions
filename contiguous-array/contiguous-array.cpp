class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int sum = 0;
        mpp[0] = -1;
        int ans = 0;
        int target = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
                sum += 1;
            else
                sum -= 1;
            if(mpp.find(sum - target) != mpp.end())
            {
                int curr = i - mpp[sum-target];
                ans = max(curr,ans);
            }
            if(mpp.find(sum) == mpp.end())
                mpp[sum] = i;
        }
        return ans;
    }
};
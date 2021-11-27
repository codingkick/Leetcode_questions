class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int val = 1;
        int count0 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                count0 += 1;
            }
            else
            {
                val *= nums[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(count0>1)
                ans.push_back(0);
            else if(count0 == 1)
            {
                if(nums[i] == 0)
                    ans.push_back(val);
                else
                    ans.push_back(0);
            }
            else
            {
                ans.push_back(val/nums[i]);
            }
        }
        return ans;
    }
};
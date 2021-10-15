class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int target = 0;
        vector<vector<int>> ans;
        while(i<n)
        {
            int v1 = nums[i];
            int p = i+1,q = n-1;
            while(p<q)
            {
                long long int val = (long long int)nums[i] + (long long int)nums[p] + (long long int)nums[q];
                int v2 = nums[p],v3 = nums[q];
                if(val == target)
                {
                    ans.push_back({v1,v2,v3});
                    while(p<q && nums[p] == v2)
                        p++;
                    while(p<q && nums[q] == v3)
                        q--;
                }
                else if(val > target)
                    q--;
                else
                    p++;
            }
            while(i<n && nums[i] == v1)
                i++;
        }
        return ans;
    }
};
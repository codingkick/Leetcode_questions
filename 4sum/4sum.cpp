class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<n)
        {
            int v1 = nums[i];
            int j = i+1;
            while(j<n)
            {
                int v2 = nums[j];
                int p = j+1,q = n-1;
                while(p<q)
                {
                    int v3 = nums[p],v4 = nums[q];
                    long long int val = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[p] + (long long int)nums[q];
                    if(val == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        while(p<q && nums[p] == v3)
                            p++;
                        while(p<q && nums[q] == v4)
                            q--;
                    }
                    else if(val > target)
                    {
                        q--;
                    }
                    else
                    {
                        p++;
                    }
                }
                while(j<n && nums[j] == v2)
                    j++;
            }
            while(i<n && nums[i] == v1)
                i++;
        }
        return ans;
    }
};
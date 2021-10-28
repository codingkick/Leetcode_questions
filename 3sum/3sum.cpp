class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i<n)
        {
            int v1 = nums[i];
            int p = i+1,q = n-1;
            while(p<q)
            {
                int val = v1 + nums[p] + nums[q];
                if(val>0)
                {
                    q--;
                }
                else if(val<0)
                {
                    p++;
                }
                else
                {
                    ans.push_back({v1,nums[p],nums[q]});
                    int v2 = nums[p],v3 = nums[q];
                    while(p<q && nums[p] == v2)
                        p++;
                    while(p>q && nums[q] == v3)
                        q--;
                }
            }
            while(i<n && nums[i] == v1)
            { 
                i++;
            }
        }
        return ans;
    }
};
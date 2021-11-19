class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(32,0);
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<32;i++)
            {
                int v1 = 1<<i;
                int v2 = nums[j]&v1;
                if(v2 != 0)
                {
                    count[i] += 1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            // cout<<count[i]<<" ";
            if(count[i]!=0)
            {
                ans += ((count[i])*(n-count[i]));
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0+nums[0];
        int n = nums.size();
        int start = 0;
        while(last<n-1)
        {
            int i = start,max_ind = last;
            // cout<<last<<"\n";
            while(i<=last)
            {
                // cout<<"i:"<<i<<"\n";
                // cout<<i+nums[i]<<"\n";
                max_ind = max(max_ind,i+nums[i]);
                if(max_ind == i+nums[i])
                    start = i;
                i++;
            }
            // cout<<max_ind<<"\n";
            if(max_ind == last)
                return false;
            else
                last = max_ind;
        }
        return true;
    }
};
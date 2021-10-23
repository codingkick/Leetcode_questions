class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n-1;
        int ind = 0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if((mid == 0 || nums[mid]<nums[mid-1]) &&(mid == n-1 || nums[mid]<nums[mid+1]))
            {
                return nums[mid];
            }
            else
            {
                if(nums[mid]>=nums[0])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return nums[0];
    }
};
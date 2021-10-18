class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            // int v1 = nums[l];
            // int v2 = nums[mid];
            // int v3 = nums[r];
            if(nums[mid] == target)
                return mid;
            else
            {
                if(nums[l]<=nums[mid])
                {
//                     homo part is l to mid
                    if(nums[l]<=target && nums[mid]>target)
                    {
                        r = mid-1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                else
                {
                    // homo part is mid to r
                    if(nums[mid] < target && nums[r]>=target)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
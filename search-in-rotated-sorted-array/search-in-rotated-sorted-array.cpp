class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int val = nums[l];
            while(l<=r)
            {
                if(nums[l]==val)
                    l++;
                else
                    break;
            }
            l--;
            val = nums[r];
            while(l<=r)
            {
                if(nums[r] == val)
                    r--;
                else
                    break;
            }
            r++;
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else
            {
                if(nums[mid]>=nums[l])
                {
//                     l to mid sorted
                    if(target>=nums[l] && target<nums[mid])
                        r = mid-1;
                    else
                        l = mid+1;
                }
                else
                {
                    // mid to r sorted
                    if(target>nums[mid] && target<=nums[r])
                        l = mid+1;
                    else
                        r = mid-1;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int v1 = nums[l],v2 = nums[r];
            while(l<=r && nums[l]==v1)
                l++;
            l--;
            while(l<=r && nums[r] == v2)
                r--;
            r++;
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return true;
            else
            {
                if(nums[mid]>=nums[l])
                {
                    if(nums[mid]>target && nums[l]<=target)
                        r = mid-1;
                    else
                        l = mid+1;
                }
                else 
                {
                    if(nums[mid]<target && nums[r]>=target)
                        l = mid+1;
                    else
                        r = mid-1;
                }
            }
        }
        return false;
    }
};
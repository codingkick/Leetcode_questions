class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if((mid==0 || nums[mid]!=nums[mid-1]) && (mid==n-1 || nums[mid]!=nums[mid+1]))
                return nums[mid];
            else
            {
                if(mid!=0 && nums[mid]==nums[mid-1])
                {
                    int count = mid-1;
                    if(count%2 == 0)
                        l = mid+1;
                    else
                        r = mid-1;
                }
                else
                {
                    int count = mid;
                    if(count%2 == 0)
                        l = mid+1;
                    else
                        r = mid-1;
                }
            }
        }
        return nums[0];
    }
};
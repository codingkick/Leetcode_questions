class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            if(mid!=0 && nums[mid] == nums[mid-1])
            {
                if((mid+1-2)%2 == 0)
                    l = mid+1;
                else
                    r = mid-1;
            }
            else if(mid!=n-1 && nums[mid] == nums[mid+1])
            {
                if((mid+1-1)%2 == 0)
                    l = mid+1;
                else
                    r = mid-1;
            }
            else
                return nums[mid];
        }
        return 0;
    }
};
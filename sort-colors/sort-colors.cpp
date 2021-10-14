class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1,mid = 0;
        while(mid<=j)
        {
            if(nums[mid] == 0)
            {
                swap(nums[i],nums[mid]);
                mid++;
                i++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[j]);
                j--;
            }
        }
    }
};
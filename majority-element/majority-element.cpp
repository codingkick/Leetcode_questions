class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int num = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] == num)
            {
                count++;
            }
            else
            {
                count -= 1;
                if(count == 0)
                {
                    count = 1;
                    num = nums[i];
                }
            }
        }
        // int c = 0;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i] == num)
        //     c++;
        // }
        // if(c>(n/2))
            return num;
        // else
        //     return -1;
    }
};
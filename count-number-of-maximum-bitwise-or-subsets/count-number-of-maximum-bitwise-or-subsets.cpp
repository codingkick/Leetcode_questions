class Solution {
public:
    int func(int ind,vector<int> &nums,int curr,int max_or)
    {
        int n = nums.size();
        if(ind == n)
        {
            if(curr == max_or)
                return 1;
            else
                return 0;
        }
        int count = func(ind+1,nums,curr|nums[ind],max_or);
        count += func(ind+1,nums,curr,max_or);
        return count;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0;
        for(int i=0;i<n;i++)
            max_or |= nums[i];
        return func(0,nums,0,max_or);
    }
};
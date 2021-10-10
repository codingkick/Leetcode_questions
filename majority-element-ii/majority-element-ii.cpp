class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int n1=INT_MAX,n2 = INT_MAX,c1 = 0,c2 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == n1)
            {
                c1 += 1;
            }
            else if(nums[i] == n2)
            {
                c2 += 1;
            }
            else if(c1 == 0)
            {
                n1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0)
            {
                n2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1 -= 1;
                c2 -= 1;
            }
        }
        // cout<<n1<<n2;
        int a = 0,b = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == n1)
            {
                a++;
            }
            else if(nums[i] == n2)
            {
                b++;
            }
        }
        vector<int> ans;
        if(a>(n/3))
            ans.push_back(n1);
        if(b>(n/3))
            ans.push_back(n2);
        return ans;
    }
};
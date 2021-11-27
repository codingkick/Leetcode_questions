class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n),mini(n);
        maxi[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            maxi[i] = max(maxi[i-1],nums[i]);
        }
        mini[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mini[i] = min(mini[i+1],nums[i]);
        }
        int left = n,right = -1;
        for(int i=0;i<n;i++)
        {
            if(maxi[i]>mini[i])
            {
                left = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(maxi[i]>mini[i])
            {
                right = i;
                break;
            }
        }
        // cout<<left<<" "<<right<<"\n";
        if(left>=right)
            return 0;
        else
            return right-left+1;
    }
};
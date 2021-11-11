class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            if(hours[i]>8)
            {
                sum += 1;
            }
            else
            {
                sum -= 1;
            }
            if(sum>0)
                ans = max(ans,i+1);
            else
            {
                int temp = sum-1;
                if(mpp.find(temp) != mpp.end())
                {
                    ans = max(ans,i-mpp[temp]);
                }
                if(mpp.find(sum) == mpp.end())
                    mpp[sum] = i;
            }
        }
        return ans;
    }
};
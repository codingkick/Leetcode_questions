class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mpp;
        int n = time.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int v1 = time[i]%60;
            int v2 = 60-v1;
            v2 = v2%60;
            if(mpp.find(v2) != mpp.end())
                ans += mpp[v2];
            if(mpp.find(v1) == mpp.end())
                mpp[v1] = 1;
            else
                mpp[v1] += 1;
        }
        return ans;
    }
};
class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int start = 0,end = 0;
        unordered_map<char,int> mpp;
        int ans = 1;
        while(end<n)
        {
            while(end<n && mpp.size() <= 1)
            {
                if(mpp.find(s[end]) == mpp.end())
                {
                    mpp[s[end]] = 1;
                }
                else
                {
                    mpp[s[end]] += 1;
                }
                end += 1;
                int curr_len = end - start;
                if(mpp.size() == 1)
                ans = max(ans,curr_len);
            }
            while(start<end && mpp.size()>1)
            {
                mpp[s[start]] -= 1;
                if(mpp[s[start]] == 0)
                    mpp.erase(s[start]);
                start += 1;
            }
        }
        return ans;
    }
};
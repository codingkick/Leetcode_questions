class Solution {
public:
    bool repeat(unordered_map<char,int> &mpp)
    {
        for(auto it:mpp)
        {
            if(it.second >1)
                return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0,end = 0;
        unordered_map<char,int> mpp;
        int ans = 0;
        while(start<n && end<n)
        {
            while(end<n && repeat(mpp) == false)
            {
                int curr_len = end-start;
                ans = max(curr_len,ans);
                if(mpp.find(s[end]) == mpp.end())
                {
                    mpp[s[end]] = 1;
                    // end++;
                }
                else
                mpp[s[end]] += 1;
                end++;
            }
            if(repeat(mpp) == false)
            {
                int curr_len = end-start;
                ans = max(curr_len,ans);
            }
            while(start<end && repeat(mpp) == true)
            {
                mpp[s[start]] -= 1;
                start++;
            }
        }
        return ans;
    }
};
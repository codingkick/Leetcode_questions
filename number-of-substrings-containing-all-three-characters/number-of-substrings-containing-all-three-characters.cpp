class Solution {
public:
    bool allPresent(unordered_map<char,int> &mpp)
    {
        if(mpp.size() == 3)
            return true;
        return false;
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        int start = 0,end = 0;
        int ans = 0;
        unordered_map<char,int> mpp;
        while(start<n && end<=n)
        {
            while(end<n && allPresent(mpp) == false)
            {
                if(mpp.find(s[end]) == mpp.end())
                    mpp[s[end]] = 1;
                else
                    mpp[s[end]] += 1;
                end++;
            }
            if(allPresent(mpp) == true)
            {
                ans += (n-end+1);
                mpp[s[start]] -= 1;
                if(mpp[s[start]] == 0)
                    mpp.erase(s[start]);
                start++;
            }
            else
                break;
        }
        return ans;
    }
};
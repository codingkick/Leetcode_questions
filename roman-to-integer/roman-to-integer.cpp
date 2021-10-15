class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int ind = 1;
        int n = s.length();
        int ans = mpp[s[0]];
        while(ind<n)
        {
            if(mpp[s[ind]]>mpp[s[ind-1]])
            {
                ans -= 2*mpp[s[ind-1]];
                ans += mpp[s[ind]];
            }
            else
            {
                ans += mpp[s[ind]];
            }
            ind++;
        }
        return ans;
    }
};
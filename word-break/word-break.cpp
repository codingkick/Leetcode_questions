// class Trie{
//     public:
//     Node()
//     {
        
//     }
//     Trie *trie = new Trie();
    
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,false);
        set<string> dict;
        for(auto it:wordDict)
            dict.insert(it);
        dp[0] = true;
        for(int i=1;i<=n;i++)
        {
            string str = "";
            for(int j=i-1;j>=0;j--)
            {
                str = s[j] + str;
                if(dp[j] == true && dict.find(str) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++)
        {
            if(mpp.find(s[i]) == mpp.end())
                mpp[s[i]] = 1;
            else
                mpp[s[i]] += 1;
        }
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        string ans = "";
        while(!pq.empty())
        {
            pair<int,char> temp= pq.top();
            int val = temp.first;
            while(val--)
            {
                ans += temp.second;
            }
            pq.pop();
        }
        return ans;
    }
};
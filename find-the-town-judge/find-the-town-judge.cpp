class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        set<int> s;
        for(int i=0;i<m;i++)
        {
            s.insert(trust[i][0]);
        }
        if(s.size() == n-1)
        {
            vector<int> arr(n+1,0);
            for(auto it:s)
            {
                arr[it] = 1;
            }
            int ans = 0;
            for(int i=1;i<=n;i++)
            {
                if(arr[i] == 0)
                    ans = i;
            }
            set<int> s2;
            for(int i=0;i<m;i++)
            {
                if(trust[i][1] == ans)
                    s2.insert(trust[i][0]);
            }
            if(s2.size() == n-1)
                return ans;
            else
                return -1;
        }
        else
            return -1;
    }
};
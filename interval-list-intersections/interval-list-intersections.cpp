class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int n1 = fl.size();
        int n2 = sl.size();
        int p = 0,q = 0;
        vector<vector<int>> ans;
        while(p<n1 && q<n2)
        {
            int a = fl[p][0];
            int b = fl[p][1];
            int c = sl[q][0];
            int d = sl[q][1];
            if(a>=c && b<=d)
            {
                ans.push_back({a,b});
                p++;
            }
            else if(a<=c && b>=c && b<=d)
            {
                ans.push_back({c,b});
                p++;
            }
            else if(d>=a && a>=c && d<=b)
            {
                ans.push_back({a,d});
                q++;
            }
            else if(c>=a && d<=b)
            {
                ans.push_back({c,d});
                q++;
            }
            else if(a>d)
            {
                q++;
            }
            else if(c>b)
            {
                p++;
            }
            else
            {
                p++;
                q++;
            }
        }
        return ans;
    }
};
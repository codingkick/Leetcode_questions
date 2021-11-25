class Solution {
public:
    int fun(vector<vector<int>> &pal,vector<int> &cut,int i)
    {
        if(i <= 0)
            return 0;
        if(cut[i] != -1)
            return cut[i];
        int val = i;
        for(int j=i;j>=0;j--)
        {
            if(pal[j][i] == 1)
            {
                val = min(val,1 + fun(pal,cut,j-1));
            }
        }
        cut[i] = val;
        return cut[i];
    }
    int func(int i,int j,string &s,vector<vector<int>> &pal)
    {
        if(pal[i][j] != -1)
            return pal[i][j];
        else
        {
            if(s[i] == s[j])
                pal[i][j] = func(i+1,j-1,s,pal);
            else
                pal[i][j] = 0;
            return pal[i][j];
        }
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> vec(n,-1);
        vector<vector<int>> pal(n,vec);
        for(int i=0;i<n;i++)
        {
            pal[i][i] = 1;
            if(i!=n-1)
            {
                if(s[i] == s[i+1])
                    pal[i][i+1] = 1;
                else
                    pal[i][i+1] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                func(i,j,s,pal);
            }
        }
        // return 0;
        vector<int> cut(n,-1);
        for(int i=0;i<n;i++)
        {
            if(pal[0][i] == 1)
                cut[i] = 0;
        }
        return fun(pal,cut,n-1);
    }
};
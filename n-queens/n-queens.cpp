class Solution {
public:
    void func(int n,vector<vector<string>> &ans,vector<int> &curr,int ind)
    {
        if(ind==n)
        {
            string s = "";
            for(int j=0;j<n;j++)
                s += '.';
            vector<string> vec(n,s);
            for(int i=0;i<n;i++)
            {
                vec[i][curr[i]] = 'Q';
            }
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(ispos(ind,i,curr) == true)
            {
                curr[ind] = i;
                func(n,ans,curr,ind+1);
            }
        }
    }
    bool ispos(int ind,int pos,vector<int> &curr)
    {
        for(int j=0;j<ind;j++)
        {
            if(curr[j] == pos || abs(curr[j]-pos) == ind-j)
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> curr(n,0);
        func(n,ans,curr,0);
        return ans;
    }
};
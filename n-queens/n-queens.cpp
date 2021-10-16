class Solution {
public:
    bool valid(vector<int> &pos,int row,int j,int n)
    {
        for(int i=0;i<row;i++)
        {
            if(pos[i] == j)
                return false;
            else if(abs(pos[i] -j) == row - i)
                return false;
        }
        return true;
    }
    void func(int ind,vector<int> &pos,int n,vector<vector<string>> &ans)
    {
        if(ind == n)
        {
            string str = "";
            for(int i=0;i<n;i++)
                str += '.';
            vector<string> vec(n,str);
            for(int i=0;i<n;i++)
            {
                vec[i][pos[i]] = 'Q';
            }
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(valid(pos,ind,i,n) == true)
            {
                pos[ind] = i;
                func(ind+1,pos,n,ans);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            pos[0] = i;
            func(1,pos,n,ans);
        }
        return ans;
    }
};
class Solution {
public:
    void func(int ind,vector<int> &c,int csum,int t,vector<int> &curr,vector<vector<int>> &ans)
    {
        int n = c.size();
        if(csum == t)
        {
            ans.push_back(curr);
            return;
        }
        if(ind>=n)
            return;
        else
        {
            if(c[ind]+csum>t)
                return;
            else
            {
                curr.push_back(c[ind]);
                func(ind+1,c,csum+c[ind],t,curr,ans);
                curr.pop_back();
                int i = ind;
                while(i<n)
                {
                    if(c[i] == c[ind])
                        i++;
                    else
                        break;
                }
                func(i,c,csum,t,curr,ans);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        func(0,candidates,0,target,curr,ans);
        return ans;
    }
};
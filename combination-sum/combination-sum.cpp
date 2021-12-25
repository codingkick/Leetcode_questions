class Solution {
public:
    void func(vector<int>& c,int t,int ind,vector<vector<int>> &ans,vector<int> &curr,int csum)
    {
        int n = c.size();
        if(ind == n)
        {
            if(csum == t)
            ans.push_back(curr);
            return;
        }
        if(csum+c[ind]<=t)
        {
            curr.push_back(c[ind]);
            func(c,t,ind,ans,curr,csum+c[ind]);
            curr.pop_back();
        }
        func(c,t,ind+1,ans,curr,csum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(candidates,target,0,ans,curr,0);
        return ans;
    }
};
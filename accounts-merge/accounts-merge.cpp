class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<string> &curr,vector<int> &vis,unordered_map<int,string> &mpp2)
    {
        vis[node] = 1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(vis[adj[node][i]] == 0)
            {
                curr.push_back(mpp2[adj[node][i]]);
                dfs(adj,adj[node][i],curr,vis,mpp2);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,pair<int,string>> mpp;
        unordered_map<int,string> mpp2;
        int node = 0;
        for(int i=0;i<n;i++)
        {
            int m = accounts[i].size();
            for(int j=1;j<m;j++)
            {
                if(mpp.find(accounts[i][j]) == mpp.end())
                {
                    mpp[accounts[i][j]] = {node,accounts[i][0]};
                    mpp2[node] = accounts[i][j];
                    node++;
                }
            }
        }
        vector<int> adj[node];
        for(int i=0;i<n;i++)
        {
            int m = accounts[i].size();
            if(m==1)
                continue;
            int prev_node = mpp[accounts[i][1]].first;
            for(int j=2;j<m;j++)
            {
                int curr_node = mpp[accounts[i][j]].first;
                adj[curr_node].push_back(prev_node);
                adj[prev_node].push_back(curr_node);
                prev_node = curr_node;
            }
        }
        vector<int> vis(node,0);
        vector<vector<string>> ans;
        for(int i=0;i<node;i++)
        {
            if(vis[i] == 0)
            {
                vector<string> curr;
                curr.push_back(mpp[mpp2[i]].second);
                curr.push_back(mpp2[i]);
                dfs(adj,i,curr,vis,mpp2);
                sort(curr.begin()+1,curr.end());
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
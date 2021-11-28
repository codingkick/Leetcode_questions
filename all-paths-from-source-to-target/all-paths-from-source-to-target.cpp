class Solution {
public:
    void gen(int node,vector<int> adj[],int final_node,vector<vector<int>> &ans,vector<int> &curr)
    {
        if(node == final_node)
        {
            curr.push_back(node);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            gen(adj[node][i],adj,final_node,ans,curr);
        }
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            int n1 = i;
            for(int j=0;j<graph[i].size();j++)
            {
                int n2 = graph[i][j];
                adj[n1].push_back(n2);
            }
        }
        vector<vector<int>> ans;
        vector<int> curr;
        gen(0,adj,n-1,ans,curr);
        return ans;
    }
};
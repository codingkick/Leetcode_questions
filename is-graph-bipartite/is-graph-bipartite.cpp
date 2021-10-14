class Solution {
public:
    bool bipar(int node,vector<int> adj[],vector<int> &col,int color)
    {
        col[node] = color;
        for(int i=0;i<adj[node].size();i++)
        {
            if(col[adj[node][i]] == -1)
            {
                int val = bipar(adj[node][i],adj,col,color^1);
                if(val == false)
                    return false;
            }
            if((col[node]^col[adj[node][i]]) == 0)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> adj[100];
        int n = graph.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                // adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i] == -1)
            {
                bool temp = bipar(i,adj,col,0);
                if(temp == false)
                    return false;
            }
        }
        return true;
    }
};
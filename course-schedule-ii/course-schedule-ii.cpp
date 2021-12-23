class Solution {
public:
    vector<int> kahn(vector<int> adj[],vector<int> &indegree,int numCourses)
    {
        vector<int> ans;
        queue<int> q1;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q1.push(i);
            }
        }
        while(!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            ans.push_back(temp);
            for(int j=0;j<adj[temp].size();j++)
            {
                indegree[adj[temp][j]] -= 1;
                if(indegree[adj[temp][j]] == 0)
                    q1.push(adj[temp][j]);
            }
        }
        if(ans.size() == numCourses)
            return ans;
        else
            return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        int n = prerequisites.size();
        for(int i=0;i<n;i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a] += 1;
        }
        return kahn(adj,indegree,numCourses);
    }
};
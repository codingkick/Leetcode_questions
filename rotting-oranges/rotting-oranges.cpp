class Solution {
public:
    void bfs(vector<vector<int>> &grid,vector<vector<int>> &dis)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q1.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        while(!q1.empty())
        {
            int s = q1.size();
            while(s--)
            {
                vector<int> temp = q1.front();
                q1.pop();
                int x = temp[0];
                int y = temp[1];
                if(x-1>=0 && grid[x-1][y] == 1 && dis[x-1][y]>dis[x][y]+1)
                {
                    dis[x-1][y] = dis[x][y]+1;
                    q1.push({x-1,y});
                }
                if(x+1<m && grid[x+1][y] == 1 && dis[x+1][y]>dis[x][y]+1)
                {
                    dis[x+1][y] = dis[x][y]+1;
                    q1.push({x+1,y});
                }
                if(y-1>=0 && grid[x][y-1] == 1 && dis[x][y-1]>dis[x][y]+1)
                {
                    dis[x][y-1] = dis[x][y]+1;
                    q1.push({x,y-1});
                }
                if(y+1<n && grid[x][y+1] == 1 && dis[x][y+1]>dis[x][y]+1)
                {
                    dis[x][y+1] = dis[x][y]+1;
                    q1.push({x,y+1});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec(n,INT_MAX);
        vector<vector<int>> dis(m,vec);
        bfs(grid,dis);
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != 0)
                {
                    ans = max(ans,dis[i][j]);
                }
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
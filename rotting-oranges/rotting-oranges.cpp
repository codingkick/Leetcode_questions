class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis)
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
                    vis[i][j] = 1;
                }
            }
        }
        int time = -1;
        while(!q1.empty())
        {
            time++;
            int s = q1.size();
            while(s--)
            {
                vector<int> temp = q1.front();
                q1.pop();
                int x = temp[0],y = temp[1];
                if(x-1>=0 && grid[x-1][y] == 1 && vis[x-1][y] == 0)
                {
                    q1.push({x-1,y});
                    vis[x-1][y] = 1;
                    grid[x-1][y] = 2;
                }
                if(x+1<m && grid[x+1][y] == 1 && vis[x+1][y] == 0)
                {
                    q1.push({x+1,y});
                    vis[x+1][y] = 1;
                    grid[x+1][y] = 2;
                }
                if(y-1>=0 && grid[x][y-1] == 1 && vis[x][y-1] == 0)
                {
                    q1.push({x,y-1});
                    vis[x][y-1] = 1;
                    grid[x][y-1] = 2;
                }
                if(y+1<n && grid[x][y+1] == 1 && vis[x][y+1] == 0)
                {
                    q1.push({x,y+1});
                    vis[x][y+1] = 1;
                    grid[x][y+1] = 2;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        if(time == -1)
            return 0;
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec(n,0);
        vector<vector<int>> vis(m,vec);
        int ans = bfs(grid,vis);
        return ans;
    }
};
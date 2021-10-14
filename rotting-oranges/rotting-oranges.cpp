class Solution {
public:
    int bfs(vector<vector<int>>& grid)
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
                }
            }
        }
        int time = 0;
        while(!q1.empty())
        {
            int s = q1.size();
            while(s--)
            {
                vector<int> temp;
                temp = q1.front();
                q1.pop();
                int x = temp[0],y = temp[1];
                if(x-1>=0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    q1.push({x-1,y});
                }
                if(y-1>=0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    q1.push({x,y-1});
                }
                if(x+1<m && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    q1.push({x+1,y});
                }
                if(y+1<n && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    q1.push({x,y+1});
                }
            }
            time++;
        }
        if(time != 0)
            return time-1;
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = bfs(grid);
        int m = grid.size();
        int n = grid[0].size();
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
        return ans;
    }
};
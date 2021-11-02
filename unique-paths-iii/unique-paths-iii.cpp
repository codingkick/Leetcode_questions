class Solution {
public:
    int ans;
    void count(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& vis,int non,int c)
    {
        if(grid[x][y] == -1)
            return;
        if(grid[x][y] == 2)
        {
            if(non == c)
            ans++;
            return;
        }
        int m = grid.size();
        int n = grid[0].size();
        vis[x][y] = 1;
        if(x-1>=0 && vis[x-1][y] == 0)
        {
            count(grid,x-1,y,vis,non,c+1);
        }
        if(x+1<m && vis[x+1][y] == 0)
        {
            count(grid,x+1,y,vis,non,c+1);
        }
        if(y-1>=0 && vis[x][y-1] == 0)
        {
            count(grid,x,y-1,vis,non,c+1);
        }
        if(y+1<n && vis[x][y+1] == 0)
        {
            count(grid,x,y+1,vis,non,c+1);
        }
        vis[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool done = false;
        vector<int> vec(n,0);
        vector<vector<int>> vis(m,vec);
        ans = 0;
        int non = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    non++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    count(grid,i,j,vis,non,-1);
                    done = true;
                    break;
                }
            }
            if(done == true)
                break;
        }
        return ans;
    }
};
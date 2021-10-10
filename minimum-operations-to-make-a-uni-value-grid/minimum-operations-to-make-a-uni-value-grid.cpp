class Solution {
public:
    int count(vector<vector<int>> &grid,int val,int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                c += abs(grid[i][j] - val)/x;
            }
        }
        // cout<<"for val : "<<val<<" = "<<c<<"\n";
        return c;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int mini = grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mini = min(grid[i][j],mini);
            }
        }
        int ans;
        vector<int> arr;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr.push_back(grid[i][j]);
                if((grid[i][j] - mini)%x != 0)
                    return -1;
            }
        }
        sort(arr.begin(),arr.end());
        if((m*n)%2 == 0)
        {
            int s = (m*n+1)/2;
            int v1 = arr[s-1];
            int v2 = arr[s];
            int val1 = count(grid,v1,x);
            int val2 = count(grid,v2,x);
            ans = min(val1,val2);
        }
        else
        {
            int s = (m*n+1)/2;
            int v1 = arr[s-1];
            ans = count(grid,v1,x);
        }
        return ans;
    }
};
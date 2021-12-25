class Solution {
public:
    int findv(int i,int j,int n)
    {
        int a = (1+(n-1-i))*n;
        int b;
        if((n-1-i)%2 == 0)
        {
            b = (n-1-j);
        }
        else
        {
            b = j;
        }
        return a-b;
    }
    vector<int> findxy(int v,int n)
    {
        int x = n-1-((v-1)/n);
        int y;
        if(((v-1)/n)%2 == 0)
            y = ((v-1)%n);
        else
            y = n - 1 - ((v-1)%n);
        return {x,y};
    }
    void bfs(vector<vector<int>>& board,vector<vector<int>>& dis)
    {
        int n = board.size();
        dis[n-1][0] = 0;
        queue<vector<int>> q1;
        q1.push({n-1,0});
        while(!q1.empty())
        {
            int s = q1.size();
            while(s--)
            {
                vector<int> temp = q1.front();
                q1.pop();
                int x = temp[0];
                int y = temp[1];
                int v1 = findv(x,y,n);
                for(int k=1;k<=6;k++)
                {
                    vector<int> t = findxy(min(v1+k,n*n),n);
                    // cout<<t[0]<<" "<<t[1]<<"\n";
                    if(board[t[0]][t[1]] == -1)
                    {
                        if(dis[x][y]+1<dis[t[0]][t[1]])
                        {
                            q1.push({t[0],t[1]});
                            dis[t[0]][t[1]] = dis[x][y]+1;
                        }
                    }
                    else
                    {
                        vector<int> t2 = findxy(board[t[0]][t[1]],n);
                        if(dis[x][y]+1<dis[t2[0]][t2[1]])
                        {
                            dis[t2[0]][t2[1]] = 1 + dis[x][y];
                            q1.push({t2[0],t2[1]});
                        }
                    }
                }
            }
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // vector<int> t3 = findxy(2,n);
        // cout<<findv(n-1,0,n);
        // cout<<t3[0]<<t3[1]<<"\n";
        vector<int> vec(n,INT_MAX);
        vector<vector<int>> dis(n,vec);
        bfs(board,dis);
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<dis[i][j]<<" ";
        //     cout<<"\n";
        // }
        vector<int> t = findxy(n*n,n);
        if(dis[t[0]][t[1]] == INT_MAX)
            return -1;
        else
            return dis[t[0]][t[1]];
    }
};
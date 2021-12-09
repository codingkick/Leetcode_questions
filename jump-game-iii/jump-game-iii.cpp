class Solution {
public:
    bool bfs(vector<int> &arr,int start)
    {
        int n = arr.size();
        vector<int> vis(n,0);
        queue<int> q1;
        q1.push(start);
        vis[start] = 1;
        while(!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            if(temp + arr[temp]<n && vis[temp+arr[temp]] == 0)
            {
                q1.push(temp+arr[temp]);
                vis[temp+arr[temp]] = 1;
                if(arr[temp+arr[temp]] == 0)
                    return true;
            }
            if(temp - arr[temp]>=0 && vis[temp - arr[temp]] == 0)
            {
                q1.push(temp - arr[temp]);
                vis[temp - arr[temp]] = 1;
                if(arr[temp - arr[temp]] == 0)
                    return true;
            }
                
            // for(int i=temp+1;i<min(temp+arr[temp]+1,n);i++)
            // {
            //     if(vis[i] == 0)
            //     {
            //         q1.push(i);
            //         vis[i] = 1;
            //     }
            //     if(arr[i] == 0)
            //         return true;
            // }
            // for(int i=temp-1;i>=max(0,temp-arr[temp]);i--)
            // {
            //     if(vis[i] == 0)
            //     {
            //         q1.push(i);
            //         vis[i] = 1;
            //     }
            //     if(arr[i] == 0)
            //         return true;
            // }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 1 && arr[i] == 0)
                return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        return bfs(arr,start);
    }
};
class Solution {
public:
    int func(int floor,int egg,vector<vector<int>> &mem)
    {
        if(mem[floor][egg] != -1)
            return mem[floor][egg];
        if(egg == 1)
            return floor;
        if(floor == 0)
            return 0;
        int ans = INT_MAX;
        int l = 1,r = floor;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int v1 = func(floor-mid,egg,mem);
            int v2 = func(mid-1,egg-1,mem);
            if(v1>v2)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            int temp = max(v1,v2);
            ans = min(ans,temp);
        }
        // for(int i=1;i<=floor;i++)
        // {
        //     int v1 = func(floor-i,egg,mem);
        //     int v2 = func(i-1,egg-1,mem);
        //     int temp = max(v1,v2);
        //     ans = min(ans,temp);
        // }
        mem[floor][egg] = ans+1;
        return ans + 1;
    }
    int superEggDrop(int k, int n) {
        vector<int> vec(k+1,-1);
        vector<vector<int>> mem(n+1,vec);
        return func(n,k,mem);
    }
};
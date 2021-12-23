class Solution {
public:
    int find_ind(vector<vector<int>> &arr,int i)
    {
        int l = 0,r = i-2;
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[mid][0]<=arr[i-1][1])
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans+1;
    }
    int func(int i,vector<int> &mem,vector<vector<int>> &arr)
    {
        if(i == 0)
            return 0;
        if(mem[i] != -1)
            return mem[i];
        else
        {
            // dont take the curr job
            int val1 = func(i-1,mem,arr);
            // take the curr job
            int ind = find_ind(arr,i);
            int val2 = func(ind,mem,arr) + arr[i-1][2];
            mem[i] = max(val1,val2);
            return mem[i];
        }
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int> mem(n+1,-1);
        return func(n,mem,arr);
    }
};
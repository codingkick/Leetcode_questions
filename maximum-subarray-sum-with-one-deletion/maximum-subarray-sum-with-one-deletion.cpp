class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return arr[0];
        vector<int> k1(n,0),k2(n,0);
        k1[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            k1[i] = max(k1[i-1],0) + arr[i];
        }
        k2[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            k2[i] = max(k2[i+1],0) + arr[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int curr_val;
            if(i == 0)
            {
                curr_val = max(arr[i],0) + max(0,k2[i+1]);
            }
            else if(i == n-1)
            {
                curr_val = max(arr[i],0) + max(0,k1[i-1]);
            }
            else
            {
                curr_val = max(0,k1[i-1]) + max(arr[i],0) + max(0,k2[i+1]);
            }
            ans = max(ans,curr_val);
        }
        if(ans==0)
        {
            ans = INT_MIN;
            for(int i=0;i<n;i++)
            {
                ans = max(ans,arr[i]);
            }
        }
        return ans;
    }
};
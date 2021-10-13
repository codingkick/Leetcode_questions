class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0] < b[0])
            return true;
        else if(a[0] == b[0])
        {
            if(a[1] < b[1])
                return false;
            else
                return true;
        }
        else
            return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        // vector<int> dp(n,1);
        int ans = 1;
        vector<int> vec;
        vec.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
            int s = vec.size();
            if(envelopes[i][1] > vec[s-1])
                vec.push_back(envelopes[i][1]);
            else
            {
                int ind = -1;
                int l = 0,r = s-1;
                while(l<=r)
                {
                    int mid = (l+r)/2;
                    if(vec[mid] < envelopes[i][1])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        ind = mid;
                        r = mid - 1;
                    }
                }
                if(ind != -1)
                vec[ind] = envelopes[i][1];
            }
        }
        // for(auto it:vec)
        //     cout<<it<<" ";
        return vec.size();
        
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
        //         {
        //             dp[i] = max(dp[i],dp[j]+1);
        //         }
        //     }
        //     ans = max(ans,dp[i]);
        // }
        // return ans;
    }
};
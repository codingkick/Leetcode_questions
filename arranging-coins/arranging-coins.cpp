class Solution {
public:
    int arrangeCoins(int n) {
        long long int l = 1,r = n;
        long long int ans=1;
        while(l<=r)
        {
            long long int mid = (l+r)/2;
            long long int val = (mid)*(mid+1)/2;
            if(val <= n)
            {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return (int)ans;
    }
};
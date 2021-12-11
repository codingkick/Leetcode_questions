class Solution {
public:
    int gcd(int a,int b)
    {
        if(a == 0)
            return b;
        return gcd(b%a,a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        // if(a>b)
        //     return nthMagicalNumber(n,b,a);
        long long int v1 = a,v2 = b;
        long long int lcm = (v1*v2)/(long long int)gcd(v1,v2);
        // cout<<lcm<<"\n";
        long long int l = 1,r = 100000000000000;
        long long int ans = 1;
        while(l<=r)
        {
            long long int mid = (l+r)/2;
            long long int val1 = mid/v1;
            long long int val2 = mid/v2;
            long long int val3 = mid/lcm;
            long long int temp = val1 + val2 - val3;
            if(temp == n)
            {
                ans = mid;
                r = mid - 1;
            }
            else if(temp > n)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        long long int mod = 1000000007;
        // cout<<ans<<"\n";
        return (int)(ans%mod);
    }
};
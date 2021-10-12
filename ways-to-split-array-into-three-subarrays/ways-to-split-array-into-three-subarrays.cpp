class Solution {
public:
    int find_a(vector<int> &psum,vector<int> &nums,int n,int i)
    {
        int l = i+1,r = n-2;
        int ind = n+1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int s = psum[mid] - psum[i];
            if(s >= psum[i])
            {
                ind = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ind;
    }
    int find_b(vector<int> &psum,vector<int> &nums,int n,int i)
    {
        int l = i+2,r = n-1;
        int ind = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int s = psum[n-1] - psum[mid-1];
            if(s >= psum[mid-1] - psum[i])
            {
                ind = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ind;
    }
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> psum(n,0);
        psum[0] = nums[0];
        long long int ans = 0;
        for(int i=1;i<n;i++)
            psum[i] = psum[i-1] + nums[i];
        for(int i=0;i<n-2;i++)
        {
            int lsum = psum[i];
            int a = find_a(psum,nums,n,i);
            int b = find_b(psum,nums,n,i);
            // cout<<"for i : "<<i<<" the a : "<<a<<" b : "<<b<<"\n";
            if(b-a>0)
            {
                ans += (b - a);
                ans = ans%1000000007;
            }
        }
        return (int)ans;
    }
};
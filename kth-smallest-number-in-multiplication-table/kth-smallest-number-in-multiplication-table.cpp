class Solution {
public:
    vector<int> find_ind(int mid,int i,int n)
    {
        int l = 1,r = n;
        int ans1 = 0,ans2=0;
        while(l<=r)
        {
            int m = (l+r)/2;
            int val = m*i;
            if(val<mid)
            {
                ans1 = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        l = 1,r = n;
        while(l<=r)
        {
            int m = (l+r)/2;
            int val = m*i;
            if(val<=mid)
            {
                ans2 = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        return {ans1,ans2};
    }
    int findKthNumber(int m, int n, int k) {
        int l = 0,r = 900000000;
        int res = 1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int countl = 0,countr=0,count=0;
            // bool pos = false;
            for(int i=1;i<=m;i++)
            {
                vector<int> tmp = find_ind(mid,i,n);
                countl += tmp[0];
                countr += tmp[1];
            }
            // cout<<"for mid : "<<mid<<" cl : "<<countl<<" cr : "<<countr<<"\n";
            if(countl <k && k<= countr)
            {
                return mid;
            }
            else if(k<=countl)
            {
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};
class Solution {
public:
    bool is_pos(vector<int> &c,int h)
    {
        int n = c.size();
        int l = 0,r = n-1;
        int geind = n,gind = n;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(c[m]>=h)
            {
                geind = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        l = 0;
        r = n-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(c[m]>h)
            {
                gind = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        geind = n-geind;
        gind = n-gind;
        // cout<<"for h:"<<h<<" gind : "<<gind<<" geind : "<<geind<<"\n";
        if(gind<=h && h<=geind)
            return true;
        return false;
    }
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin(),c.end());
        int l = 0,r = n;
        int ans = 0;
        for(int i=0;i<=1000;i++)
        {
            int h = i;
            if(is_pos(c,h) == true)
            {
                ans = h;
            }
        }
        return ans;
    }
};
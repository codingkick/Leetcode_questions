class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2,nums1);
        int s = (n1+n2+1)/2;
        float ans;
        // if(n1 == 0)
        // {
        //     if(s%2 == 0)
        //     {
        //         ans = (double)nums2[s-1] + (double)nums2[s]/2.0;
        //     }
        //     else
        //         ans = (double)nums2[s-1]/1.0;
        //     return ans;
        // }
        int l = 0,r = n1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int onel = mid,oner = (n1 - mid);
            int twol = (s-onel), twor = (n2 - twol);
            int ul,ur,ll,lr;
            if(onel == 0)
                ul = INT_MIN;
            else
                ul = nums1[onel-1];
            if(oner == 0)
                ur = INT_MAX;
            else
                ur = nums1[mid];
            
            if(twol == 0)
                ll = INT_MIN;
            else
                ll = nums2[twol-1];
            if(twor == 0)
                lr = INT_MAX;
            else
                lr = nums2[twol];
            if(lr>=ul && ur>=ll)
            {
                // cout<<mid;
                if((n1+n2)%2 == 0)
                    ans = ((double)max(ul,ll) + (double)min(ur,lr))/2.0;
                else
                    ans = (double)max(ul,ll)/1.0;
                break;
            }
            else if(ur<ll)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
    }
};
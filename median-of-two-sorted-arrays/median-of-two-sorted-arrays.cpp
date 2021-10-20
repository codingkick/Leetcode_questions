class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        int s1 = (n1+n2+1)/2;
        int l = 0,r = n1;
        int ind;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int l1 = mid;
            int r1 = (n1 -l1);
            int l2 = (s1-l1);
            int r2 = (n2 - l2);
            int u1 = INT_MIN,v1 = INT_MIN;
            int u2 = INT_MAX,v2 = INT_MAX;
            if(l1!=0)
            {
                u1 = nums1[l1-1];
            }
            if(r1!=0)
            {
                u2 = nums1[l1];
            }
            if(l2!=0)
            {
                v1 = nums2[l2-1];
            }
            if(r2!=0)
            {
                v2 = nums2[l2];
            }
            if(u1<=v2 && v1<=u2)
            {
                // ind = mid;
                // break;
                if((n1+n2)%2 == 0)
                {
                    double ans = ((double)max(u1,v1) + (double)min(u2,v2))/2.0;
                    return ans;
                }
                else
                {
                    double ans = (double)max(u1,v1)/1.0;
                    return ans;
                }
            }
            else
            {
                if(u2<v1)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
        }
        return 0.0;
    }
};
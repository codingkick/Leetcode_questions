class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m-1;
        for(int i=m+n-1;i>=n;i--)
        {
            nums1[i] = nums1[k];
            k--;
        }
        // for(int i=0;i<m+n;i++)
        //     cout<<nums1[i]<<" ";
        int i=0;
        int p = n,q=0;
        while(i<m+n && p<m+n && q<n)
        {
            if(nums1[p]<=nums2[q])
            {
                nums1[i] = nums1[p];
                i++;
                p++;
            }
            else
            {
                nums1[i] = nums2[q];
                i++;
                q++;
            }
        }
        while(p<m+n)
        {
            nums1[i] = nums1[p];
            i++;
            p++;
        }
        while(q<n)
        {
            nums1[i] = nums2[q];
            i++;
            q++;
        }
    }
};
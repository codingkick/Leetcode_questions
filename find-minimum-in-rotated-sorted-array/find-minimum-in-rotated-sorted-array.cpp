class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if((mid == 0 || a[mid]<a[mid-1]) && (mid == n-1 || a[mid]<a[mid+1]))
                return a[mid];
            else if(a[mid]<a[r])
            {
                r = mid-1;
            }
            else if(a[mid]>a[l])
            {
                l = mid+1;
            }
            else
            {
                if(a[mid] == a[r] && a[mid]!=a[l])
                    r--;
                else if(a[mid] == a[l] && a[mid]!=a[r])
                    l++;
                else
                {
                    l++;
                    r--;
                }
            }
        }
        return a[0];
    }
};
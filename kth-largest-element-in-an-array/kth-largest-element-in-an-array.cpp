class Solution {
public:
    int partition(vector<int> &nums,int l,int r)
    {
        int p = l,q = r;
        int val = nums[r];
        int k = p;
        while(k<=q)
        {
            if(nums[k]<val)
            {
                swap(nums[p],nums[k]);
                p++;
                k++;
            }
            else if(nums[k]>val)
            {
                swap(nums[k],nums[q]);
                q--;
            }
            else
                k++;
        }
        return k;
    }
    int quicksort(vector<int> &nums,int k,int l,int r)
    {
        int pi = partition(nums,l,r);
        // cout<<pi<<"\n";
        if(pi == k)
            return nums[pi-1];
        else if(pi>k)
            return quicksort(nums,k,l,pi-2);
        else
            return quicksort(nums,k,pi,r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // cout<<partition(nums,0,1)<<"\n";
        return quicksort(nums,n+1-k,0,n-1);
    }
};
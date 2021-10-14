class Solution {
public:
    void merge(vector<int> &nums,int l,int mid,int r)
    {
        vector<int> arr;
        int i = l,j = mid + 1;
        while(i<=mid && j<=r)
        {
            if(nums[i]<=nums[j])
            {
                arr.push_back(nums[i]);
                i++;
            }
            else
            {
                arr.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            arr.push_back(nums[i]);
            i++;
        }
        while(j<=r)
        {
            arr.push_back(nums[j]);
            j++;
        }
        int m = 0;
        for(int k=l;k<=r;k++)
        {
            nums[k] = arr[m];
            m++;
        }
    }
    int mergesort(vector<int> &nums,int l,int r)
    {
        if(l>=r)
            return 0;
        else
        {
            int count = 0;
            int mid = l + (r-l)/2;
            count += mergesort(nums,l,mid);
            count += mergesort(nums,mid+1,r);
            int i = l,j=mid+1;
            while(i<=mid)
            {
                while(j<=r && nums[i]/2.0 > nums[j])
                {
                    j++;
                }
                i++;
                count += (j-mid-1);
            }
            // merge(nums,l,mid,r);
            stable_sort(nums.begin() + l,nums.begin() + r+1);
            return count;
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};
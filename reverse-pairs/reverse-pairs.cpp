class Solution {
public:
    void merge(vector<int> &nums,int l,int mid,int r)
    {
        vector<int> arr;
        int p=l,q=mid+1;
        while(p<=mid && q<=r)
        {
            if(nums[p]<=nums[q])
            {
                arr.push_back(nums[p]);
                p++;
            }
            else
            {
                arr.push_back(nums[q]);
                q++;
            }
        }
        while(p<=mid)
        {
            arr.push_back(nums[p]);
            p++;
        }
        while(q<=r)
        {
            arr.push_back(nums[q]);
            q++;
        }
        int k = 0;
        for(int i=l;i<=r;i++)
        {
            nums[i] = arr[k];
            k++;
        }
    }
    int mergesort(vector<int> &nums,int l,int r)
    {
        if(l>=r)
            return 0;
        int mid = (l+r)/2;
        int count = 0;
        count += mergesort(nums,l,mid);
        count += mergesort(nums,mid+1,r);
        int i=l,j=mid+1;
        int val = 0;
        while(i<=mid)
        {
            while(j<=r)
            {
                if((double)nums[i]/2.0 > (double)nums[j])
                {
                    j++;
                }
                else
                    break;
            }
            count += (j-(mid+1)+1)-1;
            val += (j-(mid+1)+1)-1;
            i++;
        }
        // cout<<val<<"\n";
        merge(nums,l,mid,r);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = n-1;
        int ans = mergesort(nums,0,n-1);
        // for(auto it:nums)
        //     cout<<it<<" ";
        return ans;
    }
};
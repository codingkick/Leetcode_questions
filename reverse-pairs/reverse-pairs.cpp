class Solution {
public:
    void merge(vector<int> &nums,int l,int mid,int r)
    {
        vector<int> temp;
        int p=l,q=mid+1;
        while(p<=mid && q<=r)
        {
            if(nums[p]<=nums[q])
            {
                temp.push_back(nums[p]);
                p++;
            }
            else
            {
                temp.push_back(nums[q]);
                q++;
            }
        }
        while(p<=mid)
        {
            temp.push_back(nums[p]);
            p++;
        }
        while(q<=r)
        {
            temp.push_back(nums[q]);
            q++;
        }
        int k = 0;
        for(int i=l;i<=r;i++)
        {
            nums[i] = temp[k];
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
        while(i<=mid)
        {
            while(j<=r)
            {
                if((double)nums[i]/2.0>nums[j])
                    j++;
                else
                    break;
            }
            count += (j-mid-1);
            i++;
        }
        merge(nums,l,mid,r);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};
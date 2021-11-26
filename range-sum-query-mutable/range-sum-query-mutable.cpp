class NumArray {
public:
    vector<int> sum;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        int val = (int)sqrt(n);
        int c = n/val;
        for(int i=0;i<c;i++)
        {
            int add = 0;
            for(int j=i*val;j<(i+1)*(val);j++)
            {
                add += nums[j];
            }
            sum.push_back(add);
        }
        int add = 0;
        if(c*val != n)
        {
            for(int i=val*c;i<n;i++)
            {
                add += nums[i];
            }
            sum.push_back(add);
        }
        // for(auto it:sum)
            // cout<<it<<" ";
        // cout<<"\n";
    }
    
    void update(int index, int value) {
        int val = (int)sqrt(n);
        int i = index/val;
        arr[index] = value;
        int add = 0;
        for(int j=i*val;j<min(n,(i+1)*val);j++)
            add += arr[j];
        sum[i] = add;
        // cout<<"sum[i] : "<<sum[i]<<"\n";
    }
    
    int sumRange(int left, int right) {
        int val = (int)sqrt(n);
        int s = left/val;
        int e = right/val;
        int res = 0;
        for(int i=s+1;i<e;i++)
            res += sum[i];
        if(s==e)
        {
            res = 0;
            for(int i=left;i<=right;i++)
                res += arr[i];
            return res;
        }
        for(int i=left;i<min(n,(s+1)*val);i++)
            res += arr[i];
        for(int i=e*val;i<=right;i++)
            res += arr[i];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> mpp,mpp2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int v = nums1[i] + nums2[j];
                if(mpp.find(v) == mpp.end())
                mpp[v] = 1;
                else
                    mpp[v] += 1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int v = nums3[i] + nums4[j];
                if(mpp2.find(v) == mpp2.end())
                mpp2[v] = 1;
                else
                    mpp2[v] += 1;
            }
        }
        int count = 0;
        for(auto it:mpp)
        {
            int v1 = it.first;
            int v2 = 0-v1;
            if(mpp2.find(v2) != mpp2.end())
            {
                count += mpp[v1] * mpp2[v2];
            }
        }
        return count;
    }
};
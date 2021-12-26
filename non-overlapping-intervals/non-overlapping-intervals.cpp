class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]<b[1])
            return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int ind = 1;
        int last = intervals[0][1];
        int count = 1;
        while(ind<n)
        {
            // cout<<intervals[ind][0]<<" "<<intervals[ind][1]<<"\n";
            if(intervals[ind][0]>=last)
            {
                count++;
                last = intervals[ind][1];
            }
            ind++;
        }
        return n-count;
    }
};
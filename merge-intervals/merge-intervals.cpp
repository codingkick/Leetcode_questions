class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int last = intervals[0][1];
        int ind = 1;
        int start = 0;
        vector<vector<int>> ans;
        while(ind<n)
        {
            if(intervals[ind][0]<=last)
            {
                last = max(last,intervals[ind][1]);
            }
            else
            {
                ans.push_back({intervals[start][0],last});
                start = ind;
                last = intervals[ind][1];
            }
            ind++;
        }
        ans.push_back({intervals[start][0],last});
        return ans;
    }
};
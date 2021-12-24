class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int ind = 0;
        int last = intervals[0][1];
        int i = 1;
        while(i<n)
        {
            if(intervals[i][0]<=last)
            {
                last = max(intervals[i][1],last);
            }
            else
            {
                ans.push_back({intervals[ind][0],last});
                ind = i;
                last = intervals[i][1];
            }
            i++;
        }
        ans.push_back({intervals[ind][0],last});
        return ans;
    }
};
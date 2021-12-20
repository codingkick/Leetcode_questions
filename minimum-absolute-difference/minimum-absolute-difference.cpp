class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int min_diff = INT_MAX;
        for(int i=1;i<n;i++)
        {
            min_diff = min(min_diff,arr[i]-arr[i-1]);
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1] == min_diff)
            {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
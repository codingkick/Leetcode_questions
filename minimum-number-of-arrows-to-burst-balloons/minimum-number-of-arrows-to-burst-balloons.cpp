class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({points[i][1],points[i][0]});
        sort(arr.begin(),arr.end());
        int last = arr[0][0];
        int ind = 1;
        int count = 1;
        while(ind<n)
        {
            if(arr[ind][1]>last)
            {
                count++;
                last = arr[ind][0];
            }
            ind++;
        }
        return count;
    }
};
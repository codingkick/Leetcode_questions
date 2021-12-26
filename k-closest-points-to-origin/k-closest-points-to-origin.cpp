class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int val = x*x + y*y;
            pq.push({val,x,y});
        }
        vector<vector<int>> ans;
        while(k--)
        {
            vector<int> temp = pq.top();
            pq.pop();
            ans.push_back({temp[1],temp[2]});
        }
        return ans;
    }
};
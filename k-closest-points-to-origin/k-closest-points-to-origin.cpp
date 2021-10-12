class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        int n = points.size();
        for(int i=0;i<k;i++)
        {
            int dis = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            pq.push({dis,points[i][0],points[i][1]});
        }
        for(int i=k;i<n;i++)
        {
            int dis = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            vector<int> temp = pq.top();
            // cout<<temp[0];
            if(temp[0]>dis)
            {
                pq.pop();
                pq.push({dis,points[i][0],points[i][1]});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp = pq.top();
            pq.pop();
            ans.push_back({temp[1],temp[2]});
        }
        return ans;
    }
};
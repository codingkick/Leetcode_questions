class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> v(n,-1);
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty())
                v[i] = s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        vector<int> v2(n,n);
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty())
                v2[i] = s.top();
            s.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            // cout<<v[i]<<" "<<v2[i]<<"\n";
            int curr_area = heights[i]*(1 + (v2[i]-i-1) + (i-v[i]-1));
            ans = max(ans,curr_area);
        }
        return ans;
    }
};
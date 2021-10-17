class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<vector<int>> pq;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            pq.push({a[i] + b[i],a[i],b[i]});
        }
        int s1 = 0,s2 = 0;
        int count = 0;
        while(!pq.empty())
        {
            vector<int> temp = pq.top();
            pq.pop();
            if(count%2 == 0)
                s1 += temp[1];
            else
                s2 += temp[2];
            count++;
        }
        if(s1 == s2)
            return 0;
        else if(s1>s2)
            return 1;
        else
            return -1;
    }
};
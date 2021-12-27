class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
            pq.push(nums[i]);
        vector<int> ans;
        while(!pq.empty())
        {
            int temp = pq.top();
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};
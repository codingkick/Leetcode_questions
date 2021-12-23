class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<vector<int>> start,end;
        for(int i=0;i<n;i++)
        {
            start.push_back({trips[i][1],trips[i][0]});
            end.push_back({trips[i][2],trips[i][0]});
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i = 0,j = 0;
        int max_requirement = 0,curr_requirement = 0;
        while(i<n)
        {
            if(end[j][0]>start[i][0])
            {
                curr_requirement += start[i][1];
                i++;
            }
            else
            {
                curr_requirement -= end[j][1];
                j++;
            }
            max_requirement = max(max_requirement,curr_requirement);
        }
        // cout<<max_requirement<<"\n";
        if(max_requirement<=capacity)
            return true;
        else
            return false;
    }
};
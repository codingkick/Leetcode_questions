class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int g = 0,c = 0;
        for(int i=0;i<n;i++)
        {
            g += gas[i];
            c += cost[i];
        }
        if(c>g)
            return -1;
        int ind = 0;
        g = 0;
        c = 0;
        int start = 0;
        while(ind<n)
        {
            if(g+gas[ind]>=c+cost[ind])
            {
                g += gas[ind];
                c += cost[ind];
            }
            else
            {
                g = 0;
                c = 0;
                start = ind+1;
            }
            ind++;
        }
        return start;
    }
};
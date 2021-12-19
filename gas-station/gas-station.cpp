class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum1 = 0,sum2 = 0;
        for(int i=0;i<n;i++)
        {
            sum1 += gas[i];
            sum2 += cost[i];
        }
        if(sum1<sum2)
            return -1;
        // vector<int> val(n,0);
        int i = 0,e = n;
        sum1 = 0,sum2 = 0;
        while(i<e)
        {
            sum1 += gas[i];
            sum2 += cost[i];
            if(sum1>=sum2)
                i++;
            else
            {
                while(e>i && sum1<sum2)
                {
                    e--;
                    sum1 += gas[e];
                    sum2 += cost[e];
                }
                // cout<<i<<"=>"<<e<<" : "<<sum1<<" "<<sum2<<" || ";
                i++;
            }
        }
        return e%n;
    }
};
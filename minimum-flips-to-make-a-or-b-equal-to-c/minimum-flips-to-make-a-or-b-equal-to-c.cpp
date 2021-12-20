class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> v1(32,0),v2(32,0),v3(32,0);
        for(int i=0;i<32;i++)
        {
            int val = (1<<i);
            // cout<<val<<"\n";
            if((a & val) != 0)
                v1[i] = 1;
            if((b & val) != 0)
                v2[i] = 1;
            if((c & val) != 0)
                v3[i] = 1;
            // cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<"\n";
        }
        int flips = 0;
        for(int i=0;i<32;i++)
        {
            // cout<<v3[i]<<" ";
            if(v3[i] == 0)
            {
                flips += v1[i] + v2[i];
            }
            else
            {
                if(v1[i] == 0 && v2[i] == 0)
                    flips += 1;
            }
        }
        return flips;
    }
};
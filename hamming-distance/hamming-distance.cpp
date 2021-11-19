class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            int val1 = 1<<i;
            int v1 = x&val1;
            int v2 = y&val1;
            if(v1!=v2)
                ans++;
        }
        return ans;
    }
};
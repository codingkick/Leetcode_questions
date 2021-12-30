class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int i=2;
        int last = 1%k;
        if(last == 0)
            return 1;
        if(k%2 == 0 || k%5 == 0)
            return -1;
        while(i<=INT_MAX)
        {
            int val = (((last*(10%k))%k) + (1%k))%k;
            if(val == 0)
                return i;
            last = val;
            i++;
        }
        return -1;
    }
};
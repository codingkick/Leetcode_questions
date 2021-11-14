class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0)
            return b;
        if(b == 0)
            return a;
        int v1 = a^b;
        int v2 = (unsigned int)(a&b)<<1;
        return getSum(v1,(int)v2);
    }
};
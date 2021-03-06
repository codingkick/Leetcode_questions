class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int pos = 0;
        while(num!=0)
        {
            if((num&1) == 0)
                ans += (1<<pos);
            pos++;
            num >>=1;
        }
        return ans;
    }
};
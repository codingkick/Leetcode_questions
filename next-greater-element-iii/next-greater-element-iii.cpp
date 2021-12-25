class Solution {
public:
    int nextGreaterElement(int n) {
        string val = "";
        bool dec = true;
        char last = '0';
        while(n!=0)
        {
            char temp = (n%10) + '0';
            if(temp<last)
                dec = false;
            last = temp;
            val = temp+val;
            n/=10;
        }
        if(dec == true)
            return -1;
        next_permutation(val.begin(),val.end());
        // cout<<val<<"\n";
        long long ans = 0;
        for(int i=0;i<val.length();i++)
        {
            ans = ans*10 + (long long)(val[i]-'0');
        }
        if(ans>INT_MAX)
            return -1;
        return (int)ans;
    }
};
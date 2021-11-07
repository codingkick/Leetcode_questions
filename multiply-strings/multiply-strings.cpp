class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(),m = num2.length();
        if(num1[0]-'0' == 0 || num2[0]-'0' == 0)
            return "0";
        if(n>m)
            return multiply(num2, num1);
        vector<int> carry(n,0),index(n);
        for(int i=0;i<n;i++)
            index[i] = -i;
        int net_carry = 0;
        string ans = "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        while(index[n-1]<m)
        {
            int total = 0;
            for(int i=0;i<n;i++)
            {
                int lower = num1[i]-'0';
                int upper = 0;
                if(index[i] >=0 && index[i] < m)
                    upper = num2[index[i]]-'0';
                int res = lower*upper + carry[i];
                int temp = res%10;
                carry[i] = res/10;
                total += temp;
                index[i] += 1;
                // cout<<res<<" ";
            }
            int v1 = (total + net_carry)%10;
            net_carry = (total + net_carry)/10;
            char v2 = v1+'0';
            // cout<<"\n";
            ans += v2;
        }
        int c = net_carry;
        for(int i=0;i<n;i++)
            c += carry[i];
        if(c!=0)
        {
            char v2 = c+'0';
            ans += v2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
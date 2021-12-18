class Solution {
public:
    int ans;
    void func(bool last,bool tight,int val,vector<string> &digits,string &sn,int l,int curr)
    {
        // cout<<val<<" || ";
        int d = digits.size();
        if(curr==l)
        {
            // cout<<val<<" : ";
            ans++;
            return;
        }
        if(last == true)
        {
//             curr index pe v 0.
            func(true,false,0,digits,sn,l,curr+1);
//             curr index pe 0 nahi.
            if(tight == true)
            {
                for(int i=0;i<d;i++)
                {
                    if(digits[i][0]<sn[curr])
                    {
                        int val2 = val*10 + (int)(digits[i][0]-'0');
                        // cout<<val2<<" || ";
                        func(false,false,val2,digits,sn,l,curr+1);
                    }
                    else if(digits[i][0] == sn[curr])
                    {
                        int val2 = val*10 + (int)(digits[i][0]-'0');
                        // cout<<val2<<" || ";
                        func(false,true,val2,digits,sn,l,curr+1);
                    }
                }
            }
            else
            {
                ans += pow((d),l-curr);
                // for(int i=0;i<d;i++)
                // {
                //     int val2 = val*10 + (int)(digits[i][0]-'0');
                    // cout<<val2<<" || ";
                    // func(false,false,val2,digits,sn,l,curr+1);
                // }
            }
        }
        else
        {
            if(tight == true)
            {
                for(int i=0;i<d;i++)
                {
                    if(digits[i][0]<sn[curr])
                    {
                        int val2 = val*10 + (int)(digits[i][0]-'0');
                        // cout<<val2<<" || ";
                        func(false,false,val2,digits,sn,l,curr+1);
                    }
                    else if(digits[i][0] == sn[curr])
                    {
                        int val2 = val*10 + (int)(digits[i][0]-'0');
                        // cout<<val2<<" || ";
                        func(false,true,val2,digits,sn,l,curr+1);
                    }
                }
            }
            else
            {
                ans += pow((d),l-curr);
                // for(int i=0;i<d;i++)
                // {
                //     int val2 = val*10 + (int)(digits[i][0]-'0');
                    // cout<<val2<<" || ";
                    // func(false,false,val2,digits,sn,l,curr+1);
                // }
            }
        }
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int temp = n;
        string sn = "";
        while(temp>0)
        {
            char val = temp%10 + '0';
            sn = val + sn;
            temp /= 10;
        }
        // cout<<sn<<"\n";
        int l = sn.length();
        ans = -1;
        // func(last,tight,val,digits,sn,l,curr);
        func(true,true,0,digits,sn,l,0);
        return ans;
    }
};
class Solution {
public:
    string ans;
    void func(int ind,bool tight,string &num,string &s)
    {
        if(ind == s.length())
        {
            ans = max(ans,num);
            // cout<<ans<<"<-\n";
            return;
        }
        if(tight == false)
        {
            string num1 = num+'9';
            // cout<<"false"<<num1<<"\n";
            func(ind+1,false,num1,s);
        }
        else
        {
            char last = num[ind-1];
            for(char i=last;i<s[ind];i++)
            {
                string num1 = num+i;
                func(ind+1,false,num1,s);
            }
            if(s[ind]>=last)
            {
                string num1 = num+s[ind];
                func(ind+1,true,num1,s);
            }
        }
    }
    int monotoneIncreasingDigits(int n) {
        string s = "";
        if(n==0)
            return 0;
        while(n>0)
        {
            char temp = n%10 + '0';
            s = temp+s;
            n/=10;
        }
        ans = "0";
        string num = "";
        for(char i='0';i<='9';i++)
        {
            string num1 = num+i;
            if(s[0]>i)
            {
                // cout<<"h : "<<num1<<"\n";
                func(1,false,num1,s);
            }
            else if(s[0] == i)
            {
                // cout<<"i : "<<num1<<"\n";
                func(1,true,num1,s);
            }
        }
        int res = 0;
        for(int i=0;i<ans.length();i++)
        {
            int temp = ans[i] -'0';
            res = res*10 + temp;
        }
        // cout<<ans<<"\n";
        return res;
    }
};
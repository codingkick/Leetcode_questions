class Solution {
public:
    pair<string,int> func(string &s,int ind)
    {
        string res = "";
        // int csb = 0;
        int n = s.length();
        while(ind<n)
        {
            while(ind<n && s[ind]>='a' && s[ind]<='z')
            {
                res += s[ind];
                ind++;
            }
            int val = 0;
            while(s[ind]>='0' && s[ind]<='9')
            {
                int temp = s[ind]-'0';
                val = val*10 + temp;
                ind++;
            }
            // cout<<val<<" ";
            if(s[ind] == ']')
            {
                // cout<<"ind:"<<ind<<"\n";
                break;
            }
            else
            {
                pair<string,int> v = func(s,ind+1);
                ind = v.second;
                // cout<<ind<<"\n";
                for(int i=0;i<val;i++)
                {
                    res += v.first;
                }
            }
        }
        // cout<<res<<" "<<ind+1<<"\n";
        return {res,ind+1};
    }
    string decodeString(string s) {
        pair<string,int> ans = func(s,0);
        return ans.first;
    }
};
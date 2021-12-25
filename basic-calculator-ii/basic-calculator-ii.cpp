class Solution {
public:
    int strtoint(string n)
    {
        int val = 0;
        for(int i=0;i<n.length();i++)
        {
            val = val*10 + (n[i]-'0');
        }
        return val;
    }
    int calculate(string str) {
        stack<int> s1;
        stack<string> s2;
        unordered_map<string,int> mpp;
        mpp["-"] = 1;
        mpp["+"] = 1;
        mpp["*"] = 3;
        mpp["/"] = 3;
        int ind = 0;
        vector<string> v1;
        string last = "";
        while(ind<str.length())
        {
            if(str[ind] == ' ')
                ind+=1;
            else
            {
                if(str[ind] == '+' || str[ind] == '-' || str[ind] == '*' || str[ind] == '/')
                {
                    v1.push_back(last);
                    last = "";
                    last += str[ind];
                    v1.push_back(last);
                    last = "";
                }
                else
                {
                    last+=str[ind];
                }
                ind += 1;
            }
        }
        if(last != "")
        v1.push_back(last);
        // for(auto it:v1)
        //     cout<<it<<" ";
        // cout<<"\n";
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i] == "+" || v1[i] == "-" || v1[i] == "*" || v1[i] == "/")
            {
                while(!s2.empty() && mpp[s2.top()]>=mpp[v1[i]])
                {
                    string t = s2.top();
                    s2.pop();
                    int n1 = s1.top();
                    s1.pop();
                    int n2 = s1.top();
                    s1.pop();
                    int r;
                    if(t == "+")
                        r = n2+n1;
                    else if(t=="-")
                        r = n2-n1;
                    else if(t=="*")
                        r = n2*n1;
                    else
                        r = n2/n1;
                    s1.push(r);
                }
                s2.push(v1[i]);
            }
            else
            {
                // cout<<v1[i]<<" ";
                int temp = strtoint(v1[i]);
                // cout<<"temp : "<<temp<<"\n";
                s1.push(temp);
            }
        }
        while(!s2.empty())
        {
            string t = s2.top();
            s2.pop();
            int n1 = s1.top();
            s1.pop();
            int n2 = s1.top();
            s1.pop();
            int r;
            if(t == "+")
                r = n2+n1;
            else if(t=="-")
                r = n2-n1;
            else if(t=="*")
                r = n2*n1;
            else
                r = n2/n1;
            s1.push(r);
        }
        return s1.top();
    }
};
class Solution {
public:
    int secondHighest(string s) {
        int n = s.size();
        vector<bool> here(10,false);
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
                here[s[i]-'0'] = true;
        }
        bool max = false;
        for(int i=9;i>=0;i--)
        {
            if(here[i] == true)
            {
                if(max == true)
                    return i;
                else
                    max = true;
            }
        }
        return -1;
    }
};
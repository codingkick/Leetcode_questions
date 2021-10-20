class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int n = s.length();
        int i=0;
        while(s[i] == ' ')
            i += 1;
        while(i<n)
        {
            string str = "";
            int j=i;
            for(j=i;j<n;j++)
            {
                if(s[j] == ' ')
                    break;
                str += s[j];
            }
            arr.push_back(str);
            while(s[j]==' ')
                j += 1;
            i = j;
        }
        if(arr.size() == 0)
            return "";
        string res = arr[arr.size()-1];
        for(int k=arr.size()-2;k>=0;k--)
        {
            res += ' ';
            res += arr[k];  
        }
        return res;
    }
};
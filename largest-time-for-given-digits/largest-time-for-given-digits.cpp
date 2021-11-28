class Solution {
public:
    void gen(int ind,vector<vector<int>> &all,vector<int> arr)
    {
        if(ind == 4)
        {
            // cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<"\n";
            all.push_back(arr);
            return;
        }
        gen(ind+1,all,arr);
        for(int i=ind+1;i<4;i++)
        {
            swap(arr[ind],arr[i]);
            gen(ind+1,all,arr);
            swap(arr[ind],arr[i]);
        }
    }
    string largestTimeFromDigits(vector<int>& arr) {
        // int left = 0;
        // int right = 2400;
        vector<vector<int>> all;
        gen(0,all,arr);
        int n = all.size();
        int res = 0;
        string ans = "";
        for(int i=0;i<n;i++)
        {
            int h1 = all[i][0];
            int h2 = all[i][1];
            int m1 = all[i][2];
            int m2 = all[i][3];
            int m =  m1*10 + m2;
            int val = h1*1000 + h2*100 +m;
            if(val>=0 && val<2400 && m<=59)
            {
                res = max(val,res);
                string curr = "";
                if(res == val)
                {
                    curr += (h1+'0');
                    curr += (h2+'0');
                    curr += ':';
                    curr += (m1+'0');
                    curr += (m2+'0');
                    ans = curr;
                }
            }
        }
        return ans;
    }
};
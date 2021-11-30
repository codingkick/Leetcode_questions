class Solution {
public:
    int max_area(vector<int> &his)
    {
        int n = his.size();
        stack<int> s;
        vector<int> left(n,-1);
        vector<int> right(n,n);
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(s.empty() == false && his[s.top()]>=his[i])
                s.pop();
            if(s.empty() == false)
                right[i] = s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        // s.clear();
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(s.empty() == false && his[s.top()]>=his[i])
                s.pop();
            if(s.empty() == false)
                left[i] = s.top();
            s.push(i);
        }
        int curr_area,ans = 0;
        for(int i=0;i<n;i++)
        {
            curr_area = (i-left[i])*his[i] + (right[i] - i)*his[i] -his[i];
            ans = max(ans,curr_area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row==0)
            return 0;
        int col = matrix[0].size();
        vector<int> his(col,0);
        for(int i=0;i<col;i++)
        {
            if(matrix[0][i] == '1')
            {
                his[i] = 1;
                // cout<<"hello\n";
            }
        }
        int res = 0;
        int a = 0;
        while(a<col)
        {
            int count = 0;
            if(matrix[0][a] == '0')
                a++;
            while(a<col && matrix[0][a] == '1')
            {
                a++;
                count++;
            }
            res = max(res,count);
            
        }
        // cout<<"res : "<<res<<"\n";
        // for(auto it:his)
        //         cout<<it<<" ";
        //     cout<<"\n";
        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] == '1')
                    his[j] = his[j]+1;
                else
                    his[j] = 0;
            }
            // for(auto it:his)
            //     cout<<it<<" ";
            // cout<<"\n";
            res = max(res,max_area(his));
        }
        return res;
    }
};
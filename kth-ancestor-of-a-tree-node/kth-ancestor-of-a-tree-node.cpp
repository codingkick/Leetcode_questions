class TreeAncestor {
public:
    vector<vector<int>> dp1;
    TreeAncestor(int n, vector<int>& parent) {
        vector<int> vec(n,-1);
        vector<vector<int>> dp(log2(n)+1,vec);
        int val = log2(n)+1;
        for(int i=0;i<n;i++)
            dp[0][i] = parent[i];
        for(int i=1;i<val;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val = dp[i-1][j];
                if(val == -1)
                    dp[i][j] = -1;
                else
                    dp[i][j] = dp[i-1][val];
            }
        }
        // for(int i=0;i<val;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        dp1 = dp;
    }
    
    int getKthAncestor(int node, int k) {
        int pos = 0;
        int curr_node = node;
        while(k!=0)
        {
            // cout<<k<<"\n";
            bool one = false;
            if((k&1) == 1)
                one = true;
            if(one == true)
            {
                int anc = pos;
                // cout<<"dp1["<<anc<<"]["<<curr_node<<"]\n";
                curr_node = dp1[anc][curr_node];
            }  
            // cout<<"cn : "<<curr_node<<"\n";
            if(curr_node == -1)
                return -1;
            k = k>>1;
            pos++;
        }
        return curr_node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
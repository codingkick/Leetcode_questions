class Solution {
public:
    int func(string w1,string w2,int i,int j,vector<vector<int>> &mem)
    {
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        if(mem[i][j] != -1)
            return mem[i][j];
        else
        {
            if(w1[i-1] == w2[j-1])
            {
                mem[i][j] = func(w1,w2,i-1,j-1,mem);
            }
            else
            {
                int v1,v2,v3;
                v1 = func(w1,w2,i,j-1,mem);
                v2 = func(w1,w2,i-1,j,mem);
                v3 = func(w1,w2,i-1,j-1,mem);
                mem[i][j] = 1 + min({v1,v2,v3});
            }
            return mem[i][j];
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        vector<int> vec(m+1,-1);
        vector<vector<int>> mem(n+1,vec);
        return func(word1,word2,n,m,mem);
    }
};
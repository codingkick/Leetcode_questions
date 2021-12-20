class Solution {
public:
    int func(string &word1,string &word2,int i,int j,vector<vector<int>> &mem)
    {
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        if(mem[i][j] != -1)
            return mem[i][j];
        else
        {
            if(word2[i-1] == word1[j-1])
                mem[i][j] = func(word1,word2,i-1,j-1,mem);
            else
            {
                int ins = func(word1,word2,i,j-1,mem);
                int del = func(word1,word2,i-1,j,mem);
                int rep = func(word1,word2,i-1,j-1,mem);
                mem[i][j] = 1 + min(min(ins,del),rep);
            }
            return mem[i][j];
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> vec(m+1,-1);
        vector<vector<int>> mem(n+1,vec);
        return func(word1,word2,n,m,mem);
    }
};
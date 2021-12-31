class Solution {
public:
    int func(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &mem)
    {
        int n = triangle.size();
        if(j>i)
            return INT_MAX;
        if(i == n-1)
            return triangle[i][j];
        if(mem[i][j]!=-1)
            return mem[i][j];
        else
        {
            int val1 = func(triangle,i+1,j,mem);
            int val2 = func(triangle,i+1,j+1,mem);
            mem[i][j] = min(val1,val2) + triangle[i][j];
            return mem[i][j];
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> vec(n,-1);
        vector<vector<int>> mem(n,vec);
        return func(triangle,0,0,mem);
    }
};
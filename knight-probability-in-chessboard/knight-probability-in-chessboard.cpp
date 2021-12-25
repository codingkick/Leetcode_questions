class Solution {
public:
    double prob(vector<vector<vector<double>>> &mem,int r,int c,int k,int n)
    {
        // cout<<r<<" "<<c<<" "<<k<<"\n";
        if(r<0 || c<0 || r>=n || c>=n)
            return 0.0;
        if(k == 0)
            return 1.0;
        if(mem[r][c][k]!=-1)
            return mem[r][c][k];
        else
        {
            double v1 = prob(mem,r-2,c+1,k-1,n);
            double v2 = prob(mem,r-1,c+2,k-1,n);
            double v3 = prob(mem,r+1,c+2,k-1,n);
            double v4 = prob(mem,r+2,c+1,k-1,n);
            double v5 = prob(mem,r+2,c-1,k-1,n);
            double v6 = prob(mem,r+1,c-2,k-1,n);
            double v7 = prob(mem,r-1,c-2,k-1,n);
            double v8 = prob(mem,r-2,c-1,k-1,n);
            mem[r][c][k] = (v1+v2+v3+v4+v5+v6+v7+v8)/8.0;
            // cout<<mem[k][r][c];
            return mem[r][c][k];
        }
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<double> vec(101,-1);
        vector<vector<double>> vec2(n,vec);
        vector<vector<vector<double>>> mem(n,vec2);
        return prob(mem,row,column,k,n);
    }
};
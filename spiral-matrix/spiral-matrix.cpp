class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ulx = 0,uly = 0,urx = 0,ury = n-1;
        int llx = m-1,lly = 0,lrx = m-1,lry = n-1;
        vector<int> ans;
        while(ans.size()<m*n)
        {
            for(int i=uly;i<=ury;i++)
                ans.push_back(matrix[ulx][i]);
            // cout<<ans.size()<<" ";
            for(int j=urx+1;j<=lrx;j++)
                ans.push_back(matrix[j][ury]);
            // cout<<ans.size()<<" ";
            if(lrx != ulx)
            {
                for(int i=lry-1;i>=lly;i--)
                ans.push_back(matrix[lrx][i]);
            }
            // cout<<ans.size()<<" ";
            if(lly != ury)
            {
                for(int j=llx-1;j>ulx;j--)
                ans.push_back(matrix[j][lly]);
            }
            // cout<<ans.size()<<" ";
            ulx += 1;
            uly += 1;
            urx += 1;
            ury -= 1;
            llx -= 1;
            lly += 1;
            lrx -= 1;
            lry -= 1;
            // cout<<ans.size()<<"\n";
            // cout<<ulx<<" "<<uly<<" || "<<urx<<" "<<ury<<" -- ";
            // cout<<llx<<" "<<lly<<" || "<<lrx<<" "<<lry<<" \n ";
        }
        return ans;
    }
};
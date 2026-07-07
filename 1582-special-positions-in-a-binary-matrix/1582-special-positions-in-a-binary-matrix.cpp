class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>rCount(m,0);
        vector<int>cCount(n,0);
        for(int r=0;r<m;++r){
            for(int c=0;c<n;++c){
                if(mat[r][c]==1){
                    rCount[r]++;
                    cCount[c]++;
                }
            }
        }
        int pos=0;
        for(int r=0;r<m;++r){
            for(int c=0;c<n;++c){
                if(mat[r][c]==1 && rCount[r]==1 && cCount[c]==1) pos++;
            }
        }
        return pos;
    }
};

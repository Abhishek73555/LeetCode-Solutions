class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        int total = m * n;
        k %= total; 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = (i * n + j + k) % total;
                int newRow = index / n;
                int newCol = index % n;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        
        return ans;
    }
};
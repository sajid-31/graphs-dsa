// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// https://leetcode.com/problems/number-of-enclaves/submissions/1619386953

/* APPROACH: another simple dfs approach to mark islands and to return the number of left over cells which cannot be connected to the borders */

class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return;
            grid[i][j]=0;
            vector<vector<int>> dir = {{0,1},{1,0}, {-1,0}, {0,-1}};
            for(auto it: dir){
                int x=it[0], y=it[1];
                dfs(grid,i+x,j+y,m,n);
            }
        }
    
        int numEnclaves(vector<vector<int>>& grid) {
            int m = grid.size(), n=grid[0].size(), count=0;
            for(int i = 0; i < m; i++){
                if(grid[i][0] == 1) dfs(grid, i, 0, m, n);
                if(grid[i][n-1] == 1) dfs(grid, i, n-1, m, n);
            }
            for(int j = 0; j < n; j++){
                if(grid[0][j] == 1) dfs(grid, 0, j, m, n);
                if(grid[m-1][j] == 1) dfs(grid, m-1, j, m, n);
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1) count++;
                }
            }
            return count;
        }
    };

// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

// https://leetcode.com/problems/max-area-of-island/submissions/1619444608

/* APPROACH: APPLY DFS ON EVERY ISLAND THAT YOU FIND AND STORE THE MAXIMUM SIZE OF ISLAND IN A VARIABLE */

class Solution {
    public:
        int dfs(int i, int j,vector<vector<int>>& grid ){
            int m=grid.size(), n=grid[0].size();
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return 0;
            grid[i][j]=0;
            int value = 0;
            vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto it: dir){
                int x=it[0], y=it[1];
                value += dfs(i+x,j+y,grid);
            }
            return 1 + value;
    
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int m=grid.size(), n=grid[0].size();
            int maxi = INT_MIN;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        maxi = max(maxi,dfs(i,j,grid));
                    }
                }
            }
            return maxi==INT_MIN? 0: maxi;
        }
    };
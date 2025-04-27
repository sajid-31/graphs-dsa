// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// https://leetcode.com/problems/number-of-islands/submissions/1618991021



/*APPROACH:  As the problem is to find the number of inslands 
we can just iterate the whole grid 
   if we encounter a '1' it means we have reached land, 
   apply DFS to traverse the connected land and turn it to '0' 
   as it is part of the same land and we have already explored it
   after each dfs, increase the count of totalIslands  by 1 (as we have explored 1 island completely)
   this approach
*/
class Solution {
    public:
        void fillIslands(int i, int j, vector<vector<char>>&grid,int m, int n){
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return ;
            grid[i][j] = '0';
            vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
            for (auto d : dir){
                int x=d[0], y=d[1];
                fillIslands(i+x,j+y,grid,m,n);
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int m=grid.size(), n=grid[0].size();
            int totalIslands = 0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1') {
                        fillIslands(i,j,grid,m,n);
                        totalIslands += 1;
                    }
                }
            }
            return totalIslands;
        }
    };
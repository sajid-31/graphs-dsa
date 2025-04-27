// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.


// https://leetcode.com/problems/surrounded-regions/submissions/1619021551

/* APPROACH: the problem is to convert the Os regions present in board which doesnot exist at the border
Traverse the edges of the board and if you find any O, convert all connected Os to it into Z
Now that we have identified and segregated all the O regions at the edges. Now traverse the whole board and convert the remaining inner Os into X. and turn back all the Zs into Os. Everything is done in place.
*/


class Solution {
    public:
        void dfs(int i, int j,vector<vector<char>>& board,int m, int n ){
            if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O') return;
            board[i][j] = 'Z';
            vector<vector<int>> dir= {{0,1},{1,0},{-1,0}, {0,-1}};
            for(auto it: dir){
                int x=it[0],y=it[1];
                dfs(i+x,j+y,board,m,n);
            }
        }
    
    
        void solve(vector<vector<char>>& board) {
            int m=board.size(), n=board[0].size();
            for(int i=0;i<m;i++){
                if (board[i][0]=='O') dfs(i,0,board,m,n);
                if (board[i][n-1]=='O') dfs(i,n-1,board,m,n);
            }
            for(int j=0;j<n;j++){
                if (board[0][j]=='O') dfs(0,j,board,m,n);
                if (board[m-1][j]=='O') dfs(m-1,j,board,m,n);
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]=='O') board[i][j]='X';
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]=='Z') board[i][j]='O';
                }
            }
        }
    };




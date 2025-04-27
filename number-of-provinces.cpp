// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.
// https://leetcode.com/problems/number-of-provinces/submissions/1619281400

/* APPROACH: To find the number of provinces we need to maintain a list of visisted nodes.
If you encounter an unvisited node, apply bfs on it to traverse all the nodes connected to it and mark them as visited.
In this way we can count the number of provinces */


class Solution {
    public:
        void bfs(int node,vector<vector<int>>& isConnected,vector<int>& vis){
            vis[node] = 1;
            for(int i=0;i<isConnected.size();i++){
                if(vis[i]==0 && isConnected[node][i]==1) bfs(i,isConnected,vis);
            }
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            int total = 0,n = isConnected.size();
            vector<int> vis(n,0);
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    total++;
                    bfs(i,isConnected,vis);
                }
            }
            return total;
        }
    };
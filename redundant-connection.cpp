// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// https://leetcode.com/problems/redundant-connection/submissions/1619307905

/* APPROACH: can be solved using the union find method 
consider the nodes to be individual nodes and keep combining them
if two nodes have the same parent before combining which means we are trying to
connect two nodes which are already present in the tree, will result in a graph.
*/ 

class Solution {
    public:
        vector<int> parent;
        int find(int x){
            return parent[x]==x ? x: find(parent[x]);
        }
        void unite(int x,int y){
            int p_x = find(x);
            int p_y = find(y);
            parent[p_x] = p_y;
        }
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            parent.resize(n+1);
            for(int i=1;i<=n;i++){
                parent[i]= i;
            }
    
            for(auto edge: edges){
                int x= edge[0], y=edge[1];
                if(find(x)==find(y)) return edge;
                unite(x,y);
            }
            return {};
            
        }
    };
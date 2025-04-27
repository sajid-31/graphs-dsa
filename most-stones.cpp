/* 
APPROACH: Another union-find problem , all stones are separate at beginning.
You can unite two stones only when they have atleast one same row/col.
try to apply unite on all combination of stones
finally you can remove all the nodes which are not the root or parent nodes (n- total parents)
*/



class Solution {
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) components++;
        }
        return n - components;
    }
};

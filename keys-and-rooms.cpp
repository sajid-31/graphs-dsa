// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

// https://leetcode.com/problems/keys-and-rooms/submissions/1619438715


class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size(),count = 0;
            vector<int> vis(n,0);
            queue<int> q;
            q.push(0);
            vis[0]=1;
            while(!q.empty()){
                int top = q.front();
                // vis[top] = 1;
                q.pop();
                count++;
                for(auto it: rooms[top]){
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            return count==n;
        }
    };
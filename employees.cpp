// A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

// Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

// The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

// The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

// Return the number of minutes needed to inform all the employees about the urgent news.

// https://leetcode.com/problems/time-needed-to-inform-all-employees/submissions/1619404854

/* APPROACH: USE BFS APPROACH BY STARTING PROPAGATING FROM THE MANAGER LEVEL AND ADD THE INFORM TIME OF EACH MANAGER
AS THE NEWS REACHES THEM
CAN BE IMPLEMENTED USING QUEUE
KEEP TRACK OF THE TIME TAKEN TO REACH EACH EMPLOYEE
*/

class Solution {
    public:
        int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            vector<vector<int>> adj(n);
            for(int i = 0; i < n; i++) {
                if(manager[i] != -1) {
                    adj[manager[i]].push_back(i);
                }
            }
            
            vector<int> timeTaken(n, 0);
            queue<int> q;
            q.push(headID);
    
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(auto emp : adj[top]){
                    timeTaken[emp] = timeTaken[top] + informTime[top];
                    q.push(emp);
                }
            }
            return *max_element(timeTaken.begin(), timeTaken.end());
        }
    };
    
class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) {
                    return false; 
                }
            }
        }
        return true;
    }
private:
    bool dfs(int num, const vector<vector<int>>& adj, vector<int>& visited){
        if(visited[num]==1)
        {
            return false;
        }
        if(visited[num]==2)
        {
            return true;
        }
        visited[num] = 1;

     
        for (int neighbor : adj[num]) {
            if (!dfs(neighbor, adj, visited)) {
                return false; 
            }
        }

    
        visited[num] = 2;
        return true;
    }
};

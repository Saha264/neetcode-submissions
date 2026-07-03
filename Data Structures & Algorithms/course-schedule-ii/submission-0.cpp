class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> path;
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited,path)) {
                    return {}; 
                }
            }
        }
        return path;
    }

private:
    bool dfs(int num, const vector<vector<int>>& adj, vector<int>& visited,vector<int>&path){
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
            if (!dfs(neighbor, adj, visited,path)) {
                return false; 
            }
        }

    
        visited[num] = 2;
        path.push_back(num);
        return true;
    }
};

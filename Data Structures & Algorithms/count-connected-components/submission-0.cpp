class Solution {
public:
    int count=0;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                continue;
            }
            else{
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
private:
    void dfs(int num,vector<vector<int>>&adj, vector<bool>&visited)
    {
        visited[num]=true;
        for(auto neighbors: adj[num])
        {
            if(visited[neighbors])
            {
                continue;
            }
            else{
                visited[neighbors]=true;
                dfs(neighbors,adj,visited);
            }
        }
    }
};

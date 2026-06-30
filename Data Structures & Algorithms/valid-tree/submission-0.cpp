class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!= (n-1))
        {
            return false;
        }

        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);
        if(!dfs(0,-1,visited,adj))
        {
            return false;
        }

        for(auto v:visited)
        {
            if(!v)
            {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int node, int parent,vector<bool>&visited,vector<vector<int>>&adj)
    {
        visited[node]=true;

        for(auto neighbor:adj[node]){
            if(neighbor==parent)
            {
                continue;
            }
            if(visited[neighbor])
            {
                return false;
            }

            if(!dfs(neighbor,node,visited,adj))
            {
                return false;
            }
        }
        return true;
    }
};

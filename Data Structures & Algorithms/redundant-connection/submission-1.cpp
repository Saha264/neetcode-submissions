class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<int> parent(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            int rootU= findParent(u,parent);
            int rootV= findParent(v,parent);

            if(rootU==rootV)
            {
                return edge;
            }

            parent[rootU]=rootV;
        }

        return {};
        
    }
private:
    int findParent(int node,vector<int>&parent)
    {
        if(parent[node]==node)
        {
            return node;
        }

        return findParent(parent[node],parent);
    }
};

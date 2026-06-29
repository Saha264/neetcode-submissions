class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int fresh=0;
        queue<pair<int, int>> rotten;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    rotten.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        vector<pair<int,int>> directions= {{0,1},{0,-1},{1,0},{-1,0}};
        int time=-1;

        while(!rotten.empty())
        {
            int size= rotten.size();
            

            for(int i=0;i<size;i++)
            {
                pair<int,int> temp= rotten.front();
                rotten.pop();
                
                for (auto& dir : directions) {
                    int nx= temp.first + dir.first;
                    int ny= temp.second + dir.second;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        rotten.push({nx,ny});
                        grid[nx][ny]=0;
                    }

                    
                }


            }
            time++;
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};

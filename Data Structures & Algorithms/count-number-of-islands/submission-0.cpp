class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    backtrack(grid,i,j);


                }
            }
        }
        return res;
    }
private:
    void backtrack(vector<vector<char>>& grid,int i, int j)
    {
        grid[i][j]=0;
        if(i!=0 && grid[i-1][j]=='1')
        {
            backtrack(grid,i-1,j);
        }
        if(j!=0 && grid[i][j-1]=='1')
        {
            backtrack(grid,i,j-1);
        }
        if(i!=grid.size()-1 && grid[i+1][j]=='1')
        {
            backtrack(grid,i+1,j);
        }
        if(j!=grid[0].size()-1 && grid[i][j+1]=='1')
        {
            backtrack(grid,i,j+1);
        }
        return;
        
    }

};

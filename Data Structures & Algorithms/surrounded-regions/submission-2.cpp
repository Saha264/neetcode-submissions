class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> visited (rows, vector<bool>(cols,false));

        queue<pair<int,int>> safe;

        for(int i=0;i<rows;i++)
        {
            if(board[i][0]=='O')
            {
                safe.push({i,0});
                visited[i][0]=true;
            }
            if(board[i][cols-1]=='O')
            {
                safe.push({i,cols-1});
                visited[i][cols-1]=true;
            }
        }
        for(int i=0;i<cols;i++)
        {
            if(board[0][i]=='O')
            {
                safe.push({0,i});
                visited[0][i]=true;
            }
            if(board[rows-1][i]=='O')
            {
                safe.push({rows-1,i});
                visited[rows-1][i]=true;
            }
        }

        while(!safe.empty())
        {
            pair<int,int> temp= safe.front();
            safe.pop();
            vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

            for(auto dir:directions)
            {
                int nx= temp.first + dir.first;
                int ny= temp.second+ dir.second;

                if(nx>=0 && nx<rows && ny>=0 && ny<cols && board[nx][ny]=='O' && !visited[nx][ny])
                {
                    safe.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]=='O')
                {
                    if(visited[i][j])
                    {
                        continue;
                    }
                    else{
                        board[i][j]='X';
                    }
                }
            }
        }
    }
};

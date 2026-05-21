class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_map<int,int>> row;
        unordered_map<int,unordered_map<int,int>> col;
        unordered_map<int,unordered_map<int,int>> grid;
        int grid_num=0;
        int num=0;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                num= board[i][j]-'0';
                if(row[i][num])
                {
                    return false;
                }
                else{
                    row[i][num]=1;
                }

                if(col[j][num])
                {
                    return false;
                }
                else{
                    col[j][num]=1;
                }

                grid_num= i/3;

                if(grid[(3 * grid_num) + (j/3)][num])
                {
                    return false;
                }
                else{
                    grid[(3 * grid_num) + (j/3)][num]=1;
                }
                
                
            }
        }

        return true;
    }
};

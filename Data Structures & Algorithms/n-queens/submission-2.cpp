class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n,string(n,'.'));

        vector<bool> rows(n, false);
        vector<bool> main_diag(2 * n - 1, false);
        vector<bool> anti_diag(2 * n - 1, false);
        backtrack(n,0,path,rows,main_diag,anti_diag);

        return res;

        
    }

private:

    void backtrack(int n, int col,vector<string>&path,vector<bool> rows,vector<bool> main_diag,vector<bool> anti_diag)
    {
        if(col==n)
        {
            res.push_back(path);
            return;

        }

        for(int row=0;row<n;row++)
        {
            int md_num= row-col +(n-1);
            int ad_num= row+col;

            if(rows[row] || main_diag[md_num] || anti_diag[ad_num])
            {
                continue;
            }

            path[row][col]='Q';
            rows[row]=true;
            main_diag[md_num]=true;
            anti_diag[ad_num]=true;
            backtrack(n,col+1,path,rows,main_diag,anti_diag);

            path[row][col]='.';
            rows[row]=false;
            main_diag[md_num]=false;
            anti_diag[ad_num]=false;



        }



    }
};

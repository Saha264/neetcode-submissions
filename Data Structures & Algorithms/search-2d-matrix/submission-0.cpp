class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int cols= matrix[0].size();

        int curr_row=0,curr_col=0;


        int right= ((rows*cols)-1);
        int left=0;
        int score =  (right + left) / 2;

        while( left<=right)
        {
            cout<<"right "<<right<<'\n';
            cout<<"left "<<left<<'\n';
            cout<<"score "<<score<<'\n';
            curr_row= score/cols;
            curr_col=score%cols;

            cout<<"curr_row "<<curr_row<<'\n';
            cout<<"curr_col "<<curr_col<<'\n';



            if(matrix[curr_row][curr_col]<target)
            {
                left=score+1;
            }
            else if (matrix[curr_row][curr_col]>target){
                right=score-1;
            }
            else{
                return true;
            }
            score =  (right + left) / 2;

        }
        return false;


        

        
    }
};

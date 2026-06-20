class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string path;

        backtrack(open,close,n,path);
        return res;


    }
private:
    void backtrack(int open,int close, int n,string&path)
    {
        if(path.size() == n*2)
        {
            
            res.push_back(path);
            return;
        }

        if(open<n)
        {
            path.push_back('(');
            
            backtrack(open+1,close,n,path);
            path.pop_back();
        }
        
        if(close<open)
        {
            path.push_back(')');
            
            backtrack(open,close+1,n,path);
            path.pop_back();
        }
    }
};

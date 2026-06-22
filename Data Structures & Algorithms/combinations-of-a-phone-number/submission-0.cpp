class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        vector<string> keypad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index=0;
        string path;
        if(digits.size()==0)
        {
            return res;
        }

        backtrack(index,path,digits,keypad);
        return res;
    }

private:
    void backtrack(int index, string&path,string&digits,vector<string> & keypad )
    {
        if(index==digits.size())
        {
            res.push_back(path);
            return;
        }

        string temp= keypad[digits[index] - '0'];
        for(char c: temp)
        {
            path.push_back(c);
            backtrack(index+1,path,digits,keypad);
            path.pop_back();
        }

    }
};

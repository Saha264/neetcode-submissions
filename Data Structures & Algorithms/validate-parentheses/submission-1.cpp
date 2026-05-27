class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        int n=s.size();
        

        for(int i=0;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
            {

                check.push(s[i]);
            }
            else{
                if(check.empty())
                {
                    return false;
                }
                char curr=check.top();
                cout<<"curr "<<curr<<'\n';
                if((curr=='{' && s[i]=='}') || (curr=='[' && s[i]==']') || (curr=='(' && s[i]==')'))
                {
                    check.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(check.empty())
        {
            return true;
        }
        else{
            return false;
        }

    
    }
};

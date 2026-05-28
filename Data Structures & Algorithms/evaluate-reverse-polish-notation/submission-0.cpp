#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int opr1=0;
        int opr2=0;
        int res=0;

        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                opr1=s.top();
                s.pop();
                opr2=s.top();
                s.pop();

                if(tokens[i]=="+")
                {
                    res= opr1+opr2;
                }
                else if(tokens[i]=="-")
                {
                    res=opr2-opr1;
                }
                else if(tokens[i]=="*")
                {
                    res=opr1*opr2;
                }
                else{
                    res=opr2/opr1;
                }
                cout<<"res "<<res<<'\n';
                s.push(res);
                
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

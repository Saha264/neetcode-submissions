class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> s;
        int max=0;
        vector<int> result(n);
        int top=0;


        for(int i=0;i<n;i++)
        {
            while(!s.empty() && temperatures[s.top()]< temperatures[i])
            {
                result[s.top()]= i-s.top();
                s.pop();
            }
            s.push(i);

        }
        return result;
    }
};

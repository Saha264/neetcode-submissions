class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> left_bound(n,-1);
        vector <int> right_bound(n,n);
        stack<int> s;

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>= heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                left_bound[i]=s.top();
            }
            s.push(i);
            //cout<<"left bound "<< left_bound[i]<<'\n';
        }

        while(!s.empty())
        {
            s.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>= heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                right_bound[i]=s.top();
            }
            s.push(i);
            

        }

        int max_area=0;
        int area=0;
        for(int i=0;i<n;i++)
        {
            cout<<"i "<<i<<'\n';
            area= heights[i] * ((right_bound[i] -left_bound[i]) - 1);
            cout<<"right_bound "<<right_bound[i]<<'\n';
            cout<<"left_bound "<<left_bound[i]<<'\n';
            cout<<"height "<<heights[i]<<'\n';
            
            cout<<"area "<<area<<'\n';

            max_area= max(area,max_area);
        }

        return max_area;

    }
};

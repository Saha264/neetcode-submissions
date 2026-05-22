class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
       

        int x=1;
        int max=0;
        left[0]=0;
        while(x<n)
        {
            if(height[x-1]>max)
            {
                max=height[x-1];
            }
            left[x]=max;
            x++;
        }
        right[n-1]=0;
        x=n-2;
        max=0;
        while(x>=0)
        {
            if(height[x+1]>max)
            {
                max=height[x+1];
            }
            right[x]=max;
            x--;
        }

       

        int cap=0;
        for(int i=0;i<n;i++)
        {
            cap+= std::max(min(left[i],right[i]) - height[i],0);
            cout<<"cap "<<cap<<'\n';
        }
        return cap;
    }
};

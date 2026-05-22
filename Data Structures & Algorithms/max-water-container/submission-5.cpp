class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max=0;
        int start=0;
        int end= heights.size()-1;
        int hieght=0;
        int area=0;

        while(end>start)
        {
            int hieght= std::min(heights[start],heights[end]);
            cout<<"End "<<heights[end]<<'\n';
            cout<<"Start "<<heights[start]<<'\n';
           



            area= hieght*(end-start);
            cout<<"Area "<<area<<'\n';
            if(area>max)
            {
                max=area;
            }

            if(heights[start]>=heights[end])
            {
                end--;
            }
            else{
                start++;
            }
            


        }
        return max;

    }
};

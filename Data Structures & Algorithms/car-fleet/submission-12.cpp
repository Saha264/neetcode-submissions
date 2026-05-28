class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int result=0;
        
        stack<double> s;

        for(int i=0;i<speed.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end(), greater<pair<int,int>>());

        for(int i=0;i<cars.size();i++)
        {
            double time= double(target- cars[i].first) /cars[i].second;
            cout<<"time "<< time<<'\n';
            if(s.empty() || time>s.top())
            {
                s.push(time);
            }
            else{
                continue;
            }
            
        }

        


        result=s.size();

        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
            counts[nums[i]]++;
        }
        int max=0;
        int select=0;

        for(int i=0;i<k;i++)
        {
            for(auto const [key,value]:counts)
            {
                if (value>max)
                {
                    max=value;
                    select=key;
                    cout<< "this is max "<<max <<"\n";
                    cout<< "this is value "<<value <<"\n";
                }
                
                
            }
            cout<<'\n';
            result.push_back(select);
            counts.erase(select);
            max=0;
        }
        return result;
    }
};

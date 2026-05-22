class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<vector<int>> result;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k= nums.size()-1;
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int target= -nums[i];
            while(k>j)
            {
                
                if(nums[j]+nums[k]== target )
                {
                    cout<<"Target "<<target<<'\n';
                    cout<<"i "<<i<<'\n';
                    cout<<"j "<<j<<'\n';
                    cout<<"k "<<k<<'\n';
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j+1]==nums[j])
                    {
                        j++;
                    }
                    while(j<k && nums[k-1]==nums[k])
                    {
                        k--;
                    }
                    j++;
                    k--;
                    continue;
                }
                if(nums[j]+nums[k]> target)
                {
                    k--;
                    continue;
                }
                if(nums[j]+nums[k]< target)
                {
                    j++;
                    continue;
                }

            }

        }
        return result;
    }
    
};

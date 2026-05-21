class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left=nums;
        vector<int> right=nums;
        vector<int> result;

        for(int i=1;i<nums.size();i++)
        {
            left[i]=left[i]*left[i-1];
        }
        for(int i=nums.size()-1;i>0;i--)
        {
            right[i-1]= right[i-1] * right[i];
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                result.push_back(right[i+1]);
            }
            else if(i==nums.size()-1)
            {
                result.push_back(left[i-1]);
            }
            else{
                result.push_back(left[i-1] * right[i+1]);
            }
        }
        return result;
    }
};

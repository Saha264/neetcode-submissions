class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            list<int> path;
            int index=0;
            backtrack(index,path,target,nums);

            return res;
    }
private:
    void backtrack(int index, list<int>& path,int target, vector<int>&nums)
    {
        int sum=0;
        for(const auto& val:path)
        {
            sum+=val;
        }
        if (sum==target)
        {
            vector<int>temp(path.begin(),path.end());
            res.push_back(temp);
            return;
        }
        if(index==nums.size() || sum>target)
        {
            return;
        }

        
        path.push_back(nums[index]);
        backtrack(index,path,target,nums);
        path.pop_back();

        backtrack(index+1,path,target,nums);
    }
};

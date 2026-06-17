class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        list<int> path;
        int start=0;
        sort(nums.begin(),nums.end());
        backtrack(start,path,nums);
        return res;
    }
private:
    void backtrack(int start, list<int>&path, vector<int>&nums)
    {
        vector<int> temp(path.begin(),path.end());
        res.push_back(temp);

        for(int i=start;i<nums.size();i++)
        {
            if(i>start && nums[i-1]==nums[i])
            {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(i+1,path,nums);
            path.pop_back();
        }
    }
};

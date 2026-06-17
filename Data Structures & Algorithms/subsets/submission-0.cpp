class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        list<int> path;
        int index=0;

        backtrack(index,path,nums);
        return res;

    }

private:
    void backtrack(int index, list<int>& path,vector<int>&nums)
    {
        if(index==nums.size())
        {
            vector<int> temp(path.begin(),path.end());
            res.push_back(temp);
            return;

        }

        //add index to path
        path.push_back(nums[index]);
        backtrack(index+1,path,nums);
        path.pop_back();

        //dont add
        backtrack(index+1,path,nums);
    }
};

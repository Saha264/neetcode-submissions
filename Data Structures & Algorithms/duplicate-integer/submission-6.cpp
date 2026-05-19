class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> done;
        for(int i=0;i<nums.size();i++)
        {
            if(done.count(nums[i]))
            {
                return true;
            }
            done.insert(nums[i]);
        }
        return false;
    }
};
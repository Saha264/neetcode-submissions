class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        list<int> path;
        int index=0;
        vector<bool> selected(nums.size(),false);
        backtrack(path,nums, selected,0);
        
        return res;
    }

private:
    void backtrack(list<int>&path, vector<int>&nums, vector<bool>& selected,int slot)
    {
        //std::cout << "Index: " << index << " | Path Size: " << path.size() << "\n";

        if(path.size()==nums.size())
        {
            vector<int>temp(path.begin(),path.end());
            res.push_back(temp);
            return;
        }
        if (slot == nums.size()) {
            return;
        }
        
        if(!selected[slot])
        {
            path.push_back(nums[slot]);
            selected[slot]=true;

            backtrack(path,nums,selected,0);
            path.pop_back();
            selected[slot]=false;
        }

        backtrack(path,nums,selected,slot+1);



        

        


    }
};

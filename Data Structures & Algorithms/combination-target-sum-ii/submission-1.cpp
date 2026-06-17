class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            list<int> path;
            int index=0;
            sort(candidates.begin(), candidates.end());
            backtrack(index,path,0,target,candidates);

            return res;
    }
private:
    void backtrack(int index, list<int>& path,int currentsum,int target, vector<int>&candidates)
    {
        

        if (currentsum==target)
        {
            vector<int>temp(path.begin(),path.end());
            res.push_back(temp);
            return;
        }
        if(index==candidates.size() || currentsum>target)
        {
            return;
        }

        
        for(int i=index;i<candidates.size();++i)
        {
            if(i>index && candidates[i-1]==candidates[i])
            {
                continue;
            }

            path.push_back(candidates[i]);
            backtrack(i+1,path, currentsum + candidates[i] ,target,candidates);
            path.pop_back();
            
        }
    }
    
};

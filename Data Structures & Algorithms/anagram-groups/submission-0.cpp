class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<bool> checked(strs.size(), false);
        vector<unordered_map<char,int>> maps(strs.size());

        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                maps[i][strs[i][j]]++;
            }
        }

        int count=0;
        int size=maps.size();
        for(int i=0;i<size;i++)
        {
            if(checked[i])
            {
                continue;
            }
            result.push_back({});
            for(int j=i;j<size;j++)
            {
                if(checked[j])
                {
                    continue;
                }
                if(maps[i]==maps[j])
                {
                    result[count].push_back(strs[j]);
                    checked[j]=true;
                    
                }
                
            }
            count++;
        }

        return result;
    }
};

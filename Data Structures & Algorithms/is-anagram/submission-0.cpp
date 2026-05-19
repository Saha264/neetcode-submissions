class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> check;

        for(int i=0;i<s.size();i++)
        {
            check[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            check[t[i]]--;
        }
        for(const auto[key,value] : check)
        {
            if(value!=0)
            {
                return false;
            }
        }
        return true;
    }
};

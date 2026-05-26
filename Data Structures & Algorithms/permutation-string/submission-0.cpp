class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> check1;
        unordered_map<char,int> check2;

        for(int i=0;i<s1.size();i++)
        {
            check1[s1[i]]++;
        }
        int window=s1.size();
        
        for(int i=0;i<window-1;i++)
        {
            check2[s2[i]]++;
        }


        int i=0;
        while(i<s2.size()-window+1)
        {
            check2[s2[i+window-1]]++;
            if(check2==check1)
            {
                return true;
            }
            else{
                if(check2[s2[i]]==1)
                {
                    check2.erase(s2[i]);
                }
                else{
                    check2[s2[i]]--;
                }
                
                i++;


            }

        }
        return false;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end= s.size()-1;



        while(start < end)
        {
            while(start < end && !isalnum(s[start]))
            {
                start++;
            }
            while(start < end && !isalnum(s[end]))
            {
                end--;
            }
            cout<<"Start: "<<s[start]<<'\n';
            cout<<"End: "<<s[end]<<'\n';
            if(tolower(s[start]) == tolower(s[end]))
            {

                start++;
                end--;
                continue;
            }

            else{
                return false;
            }
        }

        return true;
    }
};

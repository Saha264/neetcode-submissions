class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> check_t;
        unordered_map <char,int> check_s;

        string result;
        int n=s.size();
        int right=0;
        int left=0;
        int min_length=1001;

        if(t.size()>n)
        {
            return "";
        }


        for(int i=0;i<t.size();i++)
        {
            check_t[t[i]]++;
        }

        int req= check_t.size();
        int formed=0;
        int start=0;

        while(right<n)
        {

            cout<<"RIght "<<s[right]<<'\n';

            

            check_s[s[right]]++;
            if(check_t[s[right]]&& check_s[s[right]]==check_t[s[right]])
            {
                formed++;
            }
            cout<<"formed "<<formed<<'\n';
            while(formed==req)
            {
                cout<<"left "<<s[left]<<'\n';
                if(right-left<min_length)
                {
                    min_length=right-left;
                    start=left;

                }

                if(check_s[s[left]]&& check_s[s[left]]==check_t[s[left]])
                {
                    formed--;
                }
                check_s[s[left]]--;
                left++;   
                
                cout<<"min_length "<<min_length<<'\n';

            }
            right++;




        }
        if(min_length!=1001)
        {
            result = s.substr(start, min_length+1);
        }
        else{
            result="";
        }
        
        return result;





        

        

    }
};

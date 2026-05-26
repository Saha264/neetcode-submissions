class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> check;

        int max_length=0;

        int right=0,left=0;
        int n=s.size();

        while(right<n)
        {
            while(!check[s[right]])
            {
                if(right<n)
                {
                    check[s[right]]=1;
                    max_length=max(max_length,right-left+1);
                    right++;
                }
                else{
                    return max_length;
                }
            }
            


            while(left<right )
            {

                    if( s[left]==s[right])
                    {
                        check[s[left]]=0;
                        left++;
                        break;
                    }
                    else{
                        check[s[left]]=0;
                        left++;
                    }
                
            }
            

            cout<<"Right "<<right<<'\n';
            cout<<"left "<<left<<'\n';
            cout<<"length "<<max_length<<'\n';

        }
        max_length=max(max_length,right-left);
        return max_length;
    }
};

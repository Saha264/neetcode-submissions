class Solution {
public:

    string encode(vector<string>& strs) {
        
        int length;
        string text;
        for(int i=0;i<strs.size();i++)
        {
            length=strs[i].length();
            //cout<<"this is length"<<length<<'\n';
            text+= to_string(length);
            text+='#';
            text+=strs[i];

            //cout<< text<<'\n';
        }
        return text;
    }

    vector<string> decode(string s) {
        vector <string> result;
        int length;
        int i=0;
        string text;
       
        while (i < s.length()) 
        {

            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            int number_of_digits = j - i; 
            length = stoi(s.substr(i, number_of_digits));

            text = s.substr(j + 1, length);
            result.push_back(text);

            i = j + 1 + length;
        }
        

        return result;
    }
};

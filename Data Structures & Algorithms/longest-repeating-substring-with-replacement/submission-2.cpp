class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char,int> check;

        int max_length=0;
        int max_count=0;
        int right=0, left=0;
        int n=s.size();

        // Use the outer loop to move 'right' forward naturally
        while(right < n)
        {
            // 1. Add the current character to the map
            check[s[right]]++;
            
            // 2. Update the highest frequency seen so far
            max_count = max(max_count, check[s[right]]);
            
            // 3. If the window becomes invalid, shrink it from the left
            // (right - left + 1) is the exact window size
            while((right - left + 1) - max_count > k)
            {
                check[s[left]]--;
                left++;
            }
            
            // 4. Record the max length of a valid window
            max_length = max(max_length, right - left + 1);
            
            // 5. Always move right forward to prevent ANY infinite loops
            right++;
        }
        
        return max_length;
    }
};
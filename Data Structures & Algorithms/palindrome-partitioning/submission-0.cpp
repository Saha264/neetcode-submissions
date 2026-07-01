#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> currentPartition;
        backtrack(0, s, currentPartition, result);
        return result;
    }

private:
    void backtrack(int start, const std::string& s, 
                   std::vector<std::string>& currentPartition, 
                   std::vector<std::vector<std::string>>& result) {
        
        // Base Case: If we've reached the end of the string, 
        // it means we found a valid partition for the entire string.
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        // Explore all possible end positions for the current substring
        for (int end = start; end < s.length(); ++end) {
            // Check if the substring s[start...end] is a palindrome
            if (isPalindrome(s, start, end)) {
                // Make a choice: take this substring
                std::string substring = s.substr(start, end - start + 1);
                currentPartition.push_back(substring);

                // Move to the next part of the string
                backtrack(end + 1, s, currentPartition, result);

                // Backtrack: undo the choice to try other splits
                currentPartition.pop_back();
            }
        }
    }

    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
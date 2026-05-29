class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;


        if (nums[left] <= nums[right]) {
            return nums[left];
        }

        while (left <= right) {
            int curr = left + (right - left) / 2;


            if (curr < right && nums[curr] > nums[curr + 1]) {
                return nums[curr + 1];
            }
            
            if (curr > left && nums[curr - 1] > nums[curr]) {
                return nums[curr];
            }

          
            if (nums[curr] > nums[right]) {
                left = curr + 1; 
            } else {
                right = curr - 1; 
            }
        }
        
        return nums[left];
    }
};
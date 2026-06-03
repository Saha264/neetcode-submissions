class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid=0;
        int curr=0;
        int check=0;


        if (nums[left] <= nums[right]) {
            mid=left;
            check=1;
        }

        while (check==0 && left <= right) {
            int curr = left + (right - left) / 2;


            if (curr < right && nums[curr] > nums[curr + 1]) {
                mid= curr + 1;
            }
            
            if (curr > left && nums[curr - 1] > nums[curr]) {
                mid= curr;
            }

          
            if (nums[curr] > nums[right]) {
                left = curr + 1; 
            } else {
                right = curr - 1; 
            }
        }

        cout<<"mid "<<mid<<'\n';
        left = 0;
        right = nums.size() - 1;

        if(mid>0 && nums[left] <= target && nums[mid-1]>=target)
        {
            
            right=mid-1;
            while(left<= right)
            {
                curr=(left+right)/2;
                if(nums[curr]==target)
                {
                    return curr;
                }
                else if(nums[curr]< target)
                {
                    left=curr+1;
                }
                else{
                    right=curr-1;
                }
            }
            return -1;
        }
        else if(nums[right]>= target && nums[mid]<= target)
        {
            cout<<"hi";
            left=mid;

            while(left<= right)
            {
                curr=(left+right)/2;
                if(nums[curr]==target)
                {
                    return curr;
                }
                else if(nums[curr]< target)
                {
                    left=curr+1;
                }
                else{
                    right=curr-1;
                }
            }
            
            return -1;

        }
        else{
            
            return -1;
        }


    }
};

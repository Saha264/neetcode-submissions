class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result=-1;
        int left=0;
        int right= nums.size()-1;
        int curr=(left+right)/2;

        while(nums[curr]!=target && left<=right)
        {
            cout<<"left "<<left<<'\n';
            cout<<"right "<<right<<'\n';

            curr=(left+right)/2;
            cout<<"curr "<<curr<<'\n';
            if(nums[curr]<target)
            {
                left=curr+1;
            }
            else {
                right=curr-1;
            }
            
            
        }
        if(nums[curr]==target)
        {
            result=curr;
        }
        return result;

    }
};

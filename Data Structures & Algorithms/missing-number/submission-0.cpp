class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum^=nums[i];
        }

        int temp=0;
        for(int i=1;i<=n;i++)
        {
            temp^=i;
        }

        return temp^sum;
    }
};

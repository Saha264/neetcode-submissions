class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> check;
        int n = nums.size();
        int count=1;
        int max=0;
        
        int j=1;
        for(int i=0;i<n;i++)
        {
            check[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(check[nums[i]-1])
            {
                continue;
            }
            cout<<"this is nums "<< nums[i]<<'\n';
            while(check[nums[i]+j])
            {
                cout<<"this is Checked "<< nums[i]+j<<'\n';
                count++;
                j++;
            }
            if(count>max)
            {
                max=count;
            }
            count=1;
            j=1;
        }
        return max;

    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
    
        int pick=nums[1];

        for(int i=1;i<n;i++)
        {
            if(i>1)
            {
                pick= nums[i]+ prev2;
            }
            int nopick= prev;

            cout<<"pick "<<pick<<'\n';
            cout<<"nopick "<<nopick<<'\n';

            int curr=max(pick,nopick);
            cout<<"curr "<<curr<<'\n';

            prev2=prev;
            prev=curr;



        }
        return prev;
    }
};

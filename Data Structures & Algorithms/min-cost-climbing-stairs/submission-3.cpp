class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+2,-1);

        return recurse(n,cost,dp);

    }

private:
    int recurse(int n,vector<int>&cost,vector<int>&dp)
    {
        if (n<=1)
        {
            return 0;

        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        return dp[n]= min(recurse(n-1,cost,dp)+cost[n-1], recurse(n-2,cost,dp)+cost[n-2]);
    }
};

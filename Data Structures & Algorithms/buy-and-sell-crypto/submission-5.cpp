class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int p=prices.size();
        int min=0;

        for(int i=0;i<p;i++)
        {
            if(prices[i]<prices[min])
            {
                min=i;
            }
            cout<<"min "<<min<<'\n';
            cout<<"i "<<i<<'\n';


            if(min < p && prices[i]-prices[min]>profit)
            {
                profit=prices[i]-prices[min];
            }
            cout<<"profit "<<profit<<'\n';
        }
        return profit;
        


    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=101;
        
        int profit=0;
        int sell=0;
        int check=0;
        int p=prices.size();
        int i=0;
        while(i<p)
        {
            while(i+1<p && check==0 && prices[i+1]<prices[i])
            {
                i++;
            }
            if(prices[i]<buy){
                buy=prices[i];
                sell=0;
            }
            
            check=1;
            i++;
            if (i >= p) break;
            
            while(i+1<p && check==1 && prices[i+1]>prices[i])
            {
                i++;
            }
            if(prices[i]>sell)
            {
                sell=prices[i];
            }

            cout<<"Buy "<<buy<<'\n';
            cout<<"Sell "<<sell<<'\n';
            if(sell-buy>profit)
            {
                profit=sell-buy;
            }
            cout<<"Profit "<<profit<<'\n';
            check=0;
            i++;
            if (i >= p) break;
            
        }
        return profit;


    }
};

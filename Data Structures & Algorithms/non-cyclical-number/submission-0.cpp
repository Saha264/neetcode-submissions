class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> check;

        while(true){
            if(n==1)
            {
                return true;
            }
            if(check[n])
            {
                return false;
            }
            check[n]=1;
            n=sumsquare(n);
        }
    }

private:
    int sumsquare(int n)
    {
        int sum=0;
        int temp;

        while(n!=0)
        {
            temp=n%10;
            sum+= temp*temp;
            n/=10;

        }
        return sum;

    }
};

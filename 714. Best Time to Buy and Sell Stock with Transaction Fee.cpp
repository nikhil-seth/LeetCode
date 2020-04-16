// 714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee){
        int n=prices.size();
        if(n<2)
            return 0;
        int c=0,h=-prices[0];
        for(int i=1;i<n;i++){
            c=max(c,h+prices[i]-fee);
            h=max(h,c-prices[i]);
        }
        return c;
    }
};

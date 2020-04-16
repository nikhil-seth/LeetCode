//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int mp=prices[prices.size()-1],prof=0;
        for(int i=prices.size()-2;i>=0;i--){
            mp=max(mp,prices[i]);
            prof=max(prof,mp-prices[i]);
        }
        return prof;
    }
};
// 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int prof=0,mval=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            mval=max(mval,prices[i]);
            if(prices[i]<mval){
                prof+=(mval-prices[i]);
                mval=prices[i];
            }
        }
        return prof;
    }
};
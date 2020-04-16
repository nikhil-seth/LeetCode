//309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        int h1s,h1d,h0b,h0d;
        h1s=h0d=0;
        h1d=-prices[0];
        h0b=-prices[0];
        for(int i=1;i<n;i++){
            h1d=max(h1d,h0b);
            h0b=h0d-prices[i]; // PEhle ke profit seh buy & we used h0d bcoz of cooldown
            h0d=max(h0d,h1s);
            h1s=h1d+prices[i];
        }
        return h1s>h0d?h1s:h0d;
    }
};
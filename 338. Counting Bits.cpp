// 338. Counting Bits
class Solution {
public:
    vector<int> countBits(int num) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int idx=1;
        vector<int> dp(num+1);
        dp[0]=0;
        for(int i=1;i<=num;i+=1){
            if(idx*2==i)
                idx=i;
            dp[i]=dp[i-idx]+1;
        }
        return dp;
    }
};

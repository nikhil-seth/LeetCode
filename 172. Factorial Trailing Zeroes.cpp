// 172. Factorial Trailing Zeroes

class Solution {
public:
    int trailingZeroes(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(n==0) return 0;
        return (n/5)+trailingZeroes(n/5);
    }
};

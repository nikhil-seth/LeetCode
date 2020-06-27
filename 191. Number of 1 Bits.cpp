// 191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(uint32_t n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int ctr=0;
        while(n>0){
            ctr+=1;
            n&=(n-1);
        }
        return ctr;
    }
};

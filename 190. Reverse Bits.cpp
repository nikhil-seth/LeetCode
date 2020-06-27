// 190. Reverse Bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        uint32_t v=0;
        for(int i=0;i<32;i+=1){
            if(n&1){
                v|=(1<<(31-i));
            }
            n=n>>1;
        }
        return v;
    }
};

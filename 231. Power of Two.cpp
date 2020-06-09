// 231. Power of Two

class Solution {
public:
    bool isPowerOfTwo(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(n==0) return 0;
        while(!(n&1))
            n=n>>1;
        //cout<<n;
        if(n==1)
            return 1;
        return 0;
    }
};
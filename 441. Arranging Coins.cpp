// 441. Arranging Coins

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    bool fn(long k,int n){
        k*=(k+1);
        k/=2;
        if(k<=n)
            return 1;
        return 0;
    }
    int arrangeCoins(int n){
        int lo=1,hi=n,mid,ans=0;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(fn(mid,n)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};

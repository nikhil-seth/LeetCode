// 69. Sqrt(x)

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int mySqrt(int x){
        int s=1,e=x,mid,ans;
        while(s<=e){
            mid=s+(e-s)/2;
            if(x/mid>=mid){
                ans=mid;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        return ans;
    }
};

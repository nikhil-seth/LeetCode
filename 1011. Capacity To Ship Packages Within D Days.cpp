// 1011. Capacity To Ship Packages Within D Days

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D){
        int lo=0,hi=0,mid;
        for(auto c:weights){
            hi+=c;
            lo=max(lo,c);
        }
        int ctr,ts;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            ctr=1; ts=0;
            for(int i=0;i<weights.size();i+=1){
                if(weights[i]+ts>mid){
                    ctr+=1;
                    ts=weights[i];
                }
                else
                    ts+=weights[i];
                if(ctr>D) break;
            }
            if(ctr<=D)
                hi=mid;
            else
                lo=mid+1;
        }
        return hi;
    }
};

// 875. Koko Eating Bananas

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H){
        int lo=1,hi=0,mid,ctr;  
        for(auto c:piles)
            hi=max(hi,c);
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            ctr=0;
            for(int i=0;i<piles.size();i+=1)
                ctr+=ceil(float(piles[i])/mid);
            if(ctr>H)
                lo=mid+1;
            else
                hi=mid;
        }
        return hi;
    }
};

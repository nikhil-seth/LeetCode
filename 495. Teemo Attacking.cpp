// 495. Teemo Attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(timeSeries.size()==0 || duration==0) return 0;
        int ps=timeSeries[0];
        int dur=timeSeries[0]+duration-1;
        int ans=0;
        for(int i=1;i<timeSeries.size();i+=1){
            if(timeSeries[i]>dur)
                ans+=(dur-ps+1),ps=timeSeries[i];
            dur=max(dur,timeSeries[i]+duration-1);
        }
        ans+=(dur-ps+1);
        return ans;
    }
};
        
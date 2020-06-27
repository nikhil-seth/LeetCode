// 135. Candy

class Solution {
public:
    int candy(vector<int>& ratings){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=ratings.size(),x=0;
        if(!n) return 0;
        int prevCandy=1,depth=0,ans=1;
        for(int i=1;i<n;i+=1){
          //  cout<<ans<<endl;
            if(ratings[i]>=ratings[i-1]){
                // 2 Cases, either ending of a dip or in between an increasing pt.
                if(depth>0){
                    //Ending of a dip. we'll update count + peak.
                    ans+=(depth*(depth+1)/2);
                    // We'll update peak's candycount, only in case when depth>=prevCandy, kuki fir depth +1 hoga.
                    if(prevCandy<=depth) ans+=(depth+1-prevCandy);
                    depth=0;
                    prevCandy=1;
                }
                // Normal Case Execution of Adding prev val.
                prevCandy=(ratings[i]==ratings[i-1]?1:prevCandy+1);
                ans+=prevCandy;
            }
            else
                depth+=1;
        }
        if(depth>0){
            ans+=(depth*(depth+1)/2);
            if(depth>=prevCandy) ans+=(depth+1-prevCandy);
        }
        return ans;
    }
};
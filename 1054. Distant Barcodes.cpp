// 1054. Distant Barcodes

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=barcodes.size(),me=0;
        vector<int> cnt(10001,0);
        for(int i=0;i<n;i+=1){
            cnt[barcodes[i]]+=1;
            me=max(me,barcodes[i]);
        }
        int idx=0;
        for(int i=1;i<=me;i+=1){
            if(cnt[i]>cnt[idx])
                idx=i;
        }
        int i=0;
        for(;cnt[idx]>0 && i<n;i+=2){
            cnt[idx]-=1;
            barcodes[i]=idx;
        }
        idx=0;
        for(;i<n;i+=2){
            while(cnt[idx]==0)
                idx+=1;
            cnt[idx]-=1;
            barcodes[i]=idx;
        }
        for(i=1;i<n;i+=2){
            while(cnt[idx]==0)
                idx+=1;
            cnt[idx]-=1;
            barcodes[i]=idx;
        }
        return barcodes;
    }
};
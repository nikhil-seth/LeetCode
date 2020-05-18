// 668. Kth Smallest Number in Multiplication Table

class Solution {
public:
    int findKthNumber(long long m, long long n, long long k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        long long lo=1,i,hi=m*n,mid,ctr,ans;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            ctr=0,i=1;
            while(i<=m)
                ctr+=(min(n,mid/i)),i+=1;
           // cout<<lo<<' '<<hi<<' '<<mid<<' '<<ctr<<' '<<s<<' '<<l<<endl;
            if(ctr>=k){
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;
    }
};

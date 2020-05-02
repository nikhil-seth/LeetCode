// 278. First Bad Version
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        long l=1,r=n,ans;
        long mid;
        ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(isBadVersion(mid)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};

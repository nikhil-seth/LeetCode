// 275. H-Index II

class Solution {
public:
    int hIndex(vector<int>& arr){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=arr.size();
        if(!n) return 0;
        int lo=0,hi=arr[n-1],mid,x,ans=1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            x=lower_bound(arr.begin(),arr.end(),mid)-arr.begin();
            if(n-x>=mid){
                lo=mid+1;
                ans=mid;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};
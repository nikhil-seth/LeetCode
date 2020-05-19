// 719. Find K-th Smallest Pair Distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lo=0,hi=nums[n-1]-nums[0],mid,ctr;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            ctr=0;
            for(int i=0,j=0;i<n;i+=1){
                while(j<n && nums[j]-nums[i]<=mid)
                    j+=1;
                ctr+=(j-i-1);
            }
            //cout<<lo<<' '<<hi<<' '<<ctr<<endl;
            if(ctr>=k)
                hi=mid;
            else
                lo=mid+1;
        }
        return hi;
    }
};
        
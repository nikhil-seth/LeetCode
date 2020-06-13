// 16. 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int lo,hi,ns,n=nums.size();
        int closestSum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n && (closestSum-target)!=0;i+=1){
            lo=i+1,hi=n-1;
            while(lo<hi){
                ns=nums[i]+nums[lo]+nums[hi];
                if(abs(closestSum-target)>abs(ns-target))
                    closestSum=ns;
                if(target==ns)
                    break;
                else if(target>ns)
                    lo+=1;
                else
                    hi-=1;
            }
        }
        return closestSum;
    }
};
        
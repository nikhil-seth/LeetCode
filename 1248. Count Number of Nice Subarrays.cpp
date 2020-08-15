// 1248. Count Number of Nice Subarrays
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        return fn(nums,k)-fn(nums,k-1);
    }
    int fn(vector<int> &nums,int k){
        int ans=0;
        for(int i=0,j=0;j<nums.size();j+=1){
            if(nums[j]%2!=0) k--;
            while(k<0){
                if(nums[i]%2!=0) k++;
                i+=1;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
};

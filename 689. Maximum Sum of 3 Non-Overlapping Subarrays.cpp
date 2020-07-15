// 689. Maximum Sum of 3 Non-Overlapping Subarrays

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> ans;
        int n=nums.size();
        vector<int> arr(n+1);
        arr[0]=1;
        for(int i=0;i<n;i+=1)
            arr[i+1]=arr[i]+nums[i];
        int dp[n+1][4];
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=3;j+=1){
            for(int i=k;i<=n;i+=1){
                dp[i][j]=max(dp[i-1][j],dp[i-k][j-1]+arr[i]-arr[i-k]);                                
            }
        }
        int j=3,i=n;
        while(j!=0 && i>=k){
            if(dp[i][j]==dp[i-1][j])
                i-=1;
            else{
                //dp[i-k][j-1]+arr[i]-arr[i-k]){
                ans.push_back(i-k);
                j-=1;
                i=i-k;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
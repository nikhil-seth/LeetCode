// 132. Palindrome Partitioning II

class Solution {
public:
    int minCut(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=s.length();
        int dp[n+1];
        for(int i=0;i<=n;i+=1)
            dp[i]=i-1;
        for(int i=0;i<n;i+=1){
            for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j+=1)
                dp[i+j+1]=min(dp[i+j+1],1+dp[i-j]);
            for(int j=1;i-j+1>=0 && i+j<n && s[i-j+1]==s[i+j];j+=1)
                dp[i+j+1]=min(dp[i+j+1],1+dp[i-j+1]);
        }
        return dp[n];
    }
};

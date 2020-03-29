class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        if(n==0 || n==1)
            return n;
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            int backup=0;
            for(int j=i;j<n;j++){
                if(i==j)
                    dp[j]=1;
                else if(s[i]==s[j]){
                    int temp=dp[j];
                    dp[j]=backup+2;
                    backup=temp;
                }
                else{
                    backup=dp[j];
                    dp[j]=max(dp[j-1],dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};
        
// Time Complexity : O(n^2)
// Space Complexity : O(n)
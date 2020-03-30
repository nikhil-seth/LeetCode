//91. Decode Ways
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(!n) return n;
        if(n==1){
            if(s[0]=='0')
                return 0;
            return 1;
        }
        if(s[0]=='0')
            return 0;
        int dp[n+1];
        dp[n]=1;
        if(s[n-1]=='0')
            dp[n-1]=0;
        else
            dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            dp[i]=dp[i+1];
            if(s[i]=='1' || (s[i]=='2' &&  s[i+1]-'0'<=6))
                dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};
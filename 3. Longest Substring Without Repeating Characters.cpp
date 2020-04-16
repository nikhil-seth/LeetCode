// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n=s.length();
        if(!n)  return n;
        int dp[256];
        memset(dp,-1,sizeof(dp));
        int l,ml,pi;
        l=ml=0,pi=0;
        for(int i=0;i<n;i++){
            if(dp[s[i]]==-1 || dp[s[i]]<pi){
                dp[s[i]]=i;
                l++;
            }
            else{
                // Found.
                if(dp)
                l=i-dp[s[i]];
                pi=dp[s[i]]+1;
                dp[s[i]]=i;
            }
            //cout<<l<<' ';
            ml=max(ml,l);
        }
        return ml;
    }
};
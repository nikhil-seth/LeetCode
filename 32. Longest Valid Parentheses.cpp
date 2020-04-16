// 32. Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=s.length(),ans=0;
        if(n<=1)
            return 0;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,l*2);
            else if(l<r)
                l=r=0;
        }
        l=r=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,l*2);
            else if(l>r)
                l=r=0;
        }
        return ans;
    }
};
        
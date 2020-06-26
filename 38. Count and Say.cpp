// 38. Count and Say

class Solution {
public:
    string countAndSay(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string ans,s;
        n-=1;
        ans="1";
        while(n--){
            s="";
            for(int i=0,j=0;i<ans.length();){
                while(j<ans.length() && ans[j]==ans[i])
                    j+=1;
                s+=to_string(j-i)+ans[i];
                i=j;
            }
            ans=s;
        }
        return ans;
    }
};

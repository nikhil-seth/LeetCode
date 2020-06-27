// 168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int n){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string ans;
        if(!n) return ans;
        while(n){
            n-=1;
            ans.push_back(n%26+'A');
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

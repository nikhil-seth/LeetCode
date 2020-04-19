// 402. Remove K Digits
class Solution {
public:
    string removeKdigits(string s, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string ans;
        for(auto c:s){
            while(ans.length() && ans.back()>c && k){
                ans.pop_back();
                k--;
            }
            if(ans.length() || c!='0')
                ans.push_back(c);
        }
        while(ans.length() && k--)
            ans.pop_back();
        return ((ans.length()==0)?"0":ans);
    }
};
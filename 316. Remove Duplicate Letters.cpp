// 316. Remove Duplicate Letters
class Solution {
public:
    string removeDuplicateLetters(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string res;
        if(s.length()==0)
            return res;
        vector<int> cnt(26,0);
        vector<bool> vis(26,0);
        for(auto c:s)
            cnt[c-'a']+=1;
        for(auto c:s){
            cnt[c-'a']--;
            if(vis[c-'a'])
                continue;
            if(res.empty()){
                res.push_back(c);
                vis[c-'a']=1;
                continue;
            }
            while(!res.empty() && c<res.back() && cnt[res.back()-'a']>0){
                vis[res.back()-'a']=0;
                res.pop_back();
            }
            res.push_back(c);
            vis[c-'a']=1;
        }
        return res;
    }
};
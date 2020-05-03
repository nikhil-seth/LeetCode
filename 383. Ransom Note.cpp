// 383. Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> vis(26,0);
        for(auto c:magazine)
            vis[c-'a']+=1;
        for(auto c:ransomNote){
            if(vis[c-'a']==0)
                return 0;
            else
                vis[c-'a']-=1;
        }
        return 1;
    }
};
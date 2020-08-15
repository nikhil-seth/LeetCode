// 1081. Smallest Subsequence of Distinct Characters

class Solution {
public:
    string removeDuplicateLetters(string text) {
        string ans;
        vector<int> v(26,-1);
        vector<bool> vis(26,0);
        for(int i=0;i<text.size();i+=1)
            v[text[i]-'a']=i;
        for(int i=0;i<text.size();i+=1){
            if(vis[text[i]-'a']) continue;
            while(!ans.empty() && ans.back()>=text[i] && v[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(text[i]);
            vis[text[i]-'a']=1;
        }
        return ans;    
    }
};
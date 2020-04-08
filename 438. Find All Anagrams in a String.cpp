//438. Find All Anagrams in a String
class Solution {
public:
    bool cmp(int c1[],int c2[]){
        for(int i=0;i<26;i++){
            if(c1[i]!=c2[i])
                return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p){
        vector<int> v;
        if(s.size()<p.size())
            return v;
        int c1[26],c2[26];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<p.size();i++){
            c1[p[i]-'a']+=1;
            c2[s[i]-'a']+=1;
        }
        for(int i=p.size();i<s.size();i++){
            if(cmp(c1,c2))
                v.push_back(i-p.size());
            c2[s[i]-'a']+=1;
            c2[s[i-p.size()]-'a']-=1;
        }
        if(cmp(c1,c2))
            v.push_back(s.size()-p.size());
        return v;
    }
};

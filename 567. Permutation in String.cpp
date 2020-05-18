// 567. Permutation in String
class Solution {
public:
    bool chk(vector<int> &c1,vector<int> &c2){
        for(int i=0;i<26;i+=1){
            if(c1[i]!=c2[i])
                return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2){
        int n=s1.size();
        if(!n) return 1;
        if(!s2.size() || n>s2.size()) return 0;
        vector<int> c1(26,0),c2(26,0);
        for(int i=0;i<n;i+=1){
            c1[s1[i]-'a']+=1;
            c2[s2[i]-'a']+=1;
        }
        for(int i=n;i<s2.size();i+=1){
            if(chk(c1,c2)) return 1;
            c2[s2[i-n]-'a']-=1;
            c2[s2[i]-'a']+=1;
        }
        return chk(c1,c2);
    }
};
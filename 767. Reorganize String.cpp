// 767. Reorganize String

class Solution {
public:
    string reorganizeString(string S){
        vector<int> m(26,0);
        for(auto c:S)
            m[c-'a']+=1;
        int idx=0;
        for(int i=0;i<26;i+=1){
            if(m[i]>m[idx])
                idx=i;
        }
        if(m[idx]>((S.length()+1)/2))
            return "";
        int i;
        for(i=0;m[idx]>0 && i<S.length();i+=2){
            S[i]='a'+idx;
            m[idx]-=1;
        }
        idx=0;
        for(;idx<26 && i<S.length();i+=2){
            while(idx<26 && m[idx]==0)
                idx+=1;
            m[idx]-=1;
            S[i]=idx+'a';
        }
        for(i=1;idx<26 && i<S.length();i+=2){
            while(idx<26 && m[idx]==0)
                idx+=1;
            S[i]=idx+'a';
            m[idx]-=1;
        }
        return S;
    }
};
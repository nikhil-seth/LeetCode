// 696. Count Binary Substrings

class Solution {
public:
    int countBinarySubstrings(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int ctr=0;
        int c[2]={0,0};
        c[s[0]-48]+=1;
        for(int i=1;i<s.length();i+=1){
            if(s[i]==s[i-1]){
                c[s[i]-48]+=1;
            }
            else{
                // When changing from 0->1 or 1->0
                c[s[i]-48]=1;
            }
            if(c[s[i]-48]<=c[49-s[i]])
                    ctr+=1;
        }
        return ctr;
    }
};

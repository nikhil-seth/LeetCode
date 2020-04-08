// 44. Wildcard Matching

class Solution {
public:
    bool isMatch(string s, string px) {
        int n=s.length();
        string p;
        for(int i=0;i<px.length();){
            if(px[i]=='*'){
                p.push_back('*');
                while( i<px.length() && px[i]=='*')
                    i++;
            }
            else{
                p.push_back(px[i]);
                i++;
            }
        }       
        int m=p.length();
        int pc,sc,ss,sp;
        ss=sp=-1;
        pc=sc=0;
        while(sc<n){
            if(s[sc]==p[pc] || p[pc]=='?'){
                sc++;
                pc++;
            }
            else if(p[pc]=='*'){
                sp=pc++;
                ss=sc;
            }
            else{
                // Case when both aren't equal
                if(sp!=-1){
                    pc=sp+1;
                    sc=++ss;
                }
                else
                    return 0;
            }
        }
        while(pc<m){
            if(p[pc]!='*')
                return 0;
            pc++;
        }
        return 1;
    }
};
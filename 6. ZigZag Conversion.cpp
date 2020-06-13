// 6. ZigZag Conversion

class Solution {
public:
    string convert(string s, int numRows){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(numRows==1) return s;
        vector<string> sr(numRows);
        for(int i=0,j=-2;i<s.length();){
            j+=2;
            for(;j<numRows && i<s.length();j+=1,i+=1)
                sr[j].push_back(s[i]);
            j-=2;
            for(;j>=0 && i<s.length();j-=1,i+=1)
                sr[j].push_back(s[i]);
        }
        s.clear();
        for(auto &x:sr)
            s.append(x);
        return s;
    }
};

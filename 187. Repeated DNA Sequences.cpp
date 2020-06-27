// 187. Repeated DNA Sequences

class Solution {
public:
    unsigned long conv(char x){
        if(x=='A') return 0;
        if(x=='C') return 1;
        if(x=='G') return 2;
        return 3;
    }
    char fn(bitset<20> &x){
        unsigned long v=x.to_ulong();
        switch(v){
            case 0: return 'A';
            case 1: return 'C';
            case 2: return 'G';
        }
        return 'T';
    }
    vector<string> findRepeatedDnaSequences(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        long val=0;
        long mask=(1<<21)-1;
        for(int i=0;i<10;i+=1){
            val=(val<<2 | conv(s[i]));
        }
        unordered_set<bitset<20>> sx,t;
        sx.insert(val);
        for(int i=10;i<s.length();i+=1){
            val=((val<<2)&mask)|conv(s[i]);
            if(sx.find(val)!=sx.end())
                t.insert(val);
            else
                sx.insert(val);
        }
        vector<string> ans;
        bitset<20> j=0;
        for(auto x:t){
            string qt;
            for(long i=0;i<10;i+=1){
                j=3;
                j=j&x;
                x=(x>>2);
                qt.push_back(fn(j));
            }
            reverse(qt.begin(),qt.end());
            ans.push_back(qt);
        }
        return ans;
    }
};

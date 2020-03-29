//392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t){
        int idx=0;
        int x;
        for(auto &c:s){
            x=t.find(c,idx);
            if(x==string::npos)
                return 0;
            else
                idx=x+1;
        }
        return 1;
    }
};
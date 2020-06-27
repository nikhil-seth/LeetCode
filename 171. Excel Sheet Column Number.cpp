// 171. Excel Sheet Column Number

class Solution {
public:
    int titleToNumber(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int val=0;
        for(auto &x:s){
            val=val*26+(x-'A')+1;
        }
        return val;
    }
};

// 17. Letter Combinations of a Phone Number

class Solution {
public:
    string v[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void bt(const string &dig,string &x,int i){
        if(dig.length()==i){
            ans.push_back(x);
            return;
        }
        int t=dig[i]-48;
        x.push_back('0');
        for(auto &qt:v[t]){
            x[i]=qt;
            bt(dig,x,i+1);
        }
        x.pop_back();
    }
    vector<string> letterCombinations(string digits){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(digits.length()==0) return ans;
        int i=0;
        string x;
        bt(digits,x,i);
        return ans;
    }
};

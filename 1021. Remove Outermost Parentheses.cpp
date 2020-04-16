// 1021. Remove Outermost Parentheses

class Solution {
public:
    string removeOuterParentheses(string S) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        string s;
        int ctr=0;
        for(auto c:S){
            if(c=='('){
                if(ctr++)
                    s.push_back('(');
            }
            else{
                if(--ctr)
                    s.push_back(')');
            }
        }
        return s;
    }
};

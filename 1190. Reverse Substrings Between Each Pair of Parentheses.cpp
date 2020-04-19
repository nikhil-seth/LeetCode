// 1190. Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string fn(string &s,int &i){
        string s1,s2;
        while(i<s.length() && s[i]!=')'){
            if(s[i]!='(')
                s1.push_back(s[i++]);
            else{
                i+=1;
                s2=fn(s,i);
                reverse(s2.begin(),s2.end());
                s1.append(s2);
                i+=1;
            }
        }
        return s1;
    }
    string reverseParentheses(string s){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i=0;
        string s2=fn(s,i);
        return s2;
    }
};
        
        
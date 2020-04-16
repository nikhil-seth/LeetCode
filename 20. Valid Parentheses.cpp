// 20. Valid Parentheses

class Solution {
    bool fn(stack<char> &s,char ch){
        if(s.empty())
            return 0;
        if(s.top()!=ch)
            return 0;
        s.pop();
        return 1;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(': case '{' :case '[':
                    st.push(s[i]);
                    break;
                case ')':
                    if(!fn(st,'('))
                       return 0;
                    break;
               case '}':
                    if(!fn(st,'{'))
                       return 0;
                    break;
               case ']':
                    if(!fn(st,'['))
                        return 0;
                    break;
            }
        }
        if(!st.empty())
            return 0;
        return 1;
    }
};

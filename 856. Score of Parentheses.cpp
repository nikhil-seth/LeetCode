// 856. Score of Parentheses

class Solution {
public:
    int scoreOfParentheses(string S){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> s;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(')
                s.push(0);
            else{
                int x;
                if(s.top()==0){
                    s.pop();
                    x=1;
                }
                else{
                    x=s.top();
                    s.pop();
                    cout<<s.top();
                    s.pop();
                    x*=2;
                }
                if(!s.empty() && s.top()!=0){
                        int y=s.top();
                        s.pop();
                        x+=y;
                        s.push(x);
                }
                else{
                    s.push(x);
                }
            }
        }
        return s.top();
    }
};
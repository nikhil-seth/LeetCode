// 150. Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> s;
        int a,b;
        for(auto v:tokens){
            if(v.length()==1 && !isdigit(v[0])){
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                switch(v[0]){
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(b-a);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(b/a);
                }
            }
            else
                s.push(stoi(v));
        }
        return s.top();
    }
};
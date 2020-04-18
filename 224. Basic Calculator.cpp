//224. Basic Calculator

class Solution {
public:
    int calculate(string S){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int tot=0,b=0;
        stack<int> s;
        s.push(1);
        s.push(1);
        for(int i=0;i<S.length();i++){
            if(isdigit(S[i])){
                b=0;
                while(isdigit(S[i]))
                    b=b*10+(S[i++]-'0');
                i--;
                tot=tot+s.top()*b;
                s.pop();
            }
            else if(S[i]==' ')
                continue;
            else if(S[i]==')')
                s.pop();
            else if(isdigit(S[i]))
                b=b*10+(S[i]-'0');
            else{
                if(S[i]=='-')
                    s.push(-1*s.top());
                else
                    s.push(s.top());
            }
        }
        return tot;
    }
};
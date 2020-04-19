// 1003. Check If Word Is Valid After Substitutions

class Solution {
public:
    bool isValid(string S) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<char> s;
        for(auto c:S){
            if(c=='c'){
                if(s.size()<2)
                    return 0;
                if(s.top()=='b')
                    s.pop();
                else
                    return 0;
                if(s.top()=='a')
                    s.pop();
                else
                    return 0;
            }
            else
                s.push(c);
        }
        return s.empty();
    }
};
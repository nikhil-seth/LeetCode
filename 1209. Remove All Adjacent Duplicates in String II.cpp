// 1209. Remove All Adjacent Duplicates in String II
class Solution {
public:
    string removeDuplicates(string S, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<char> s;
        string s2;
        stack<int> ctr;
        if(S.length()==0)
            return s2;
        int l=0;
        s.push(S[0]);
        for(int i=0;i<S.length();i++){
            if(s.empty()){
                l=1;
                s.push(S[i]);
            }
            else if(S[i]==s.top())
                l+=1;
            else if(S[i]!=s.top()){
                ctr.push(l);
                l=1;
                s.push(S[i]);
            }
            if(l==k){
                s.pop();
                if(!ctr.empty()){
                    l=ctr.top();
                    ctr.pop();
                }
                else
                    l=0;
            }
        }
        if(l!=0)
            ctr.push(l);
        while(!s.empty()){
            l=ctr.top();
            while(l--)
                s2.push_back(s.top());
            s.pop();
            ctr.pop();
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
};

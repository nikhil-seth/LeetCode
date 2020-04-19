//394. Decode String

class Solution {
public:
    string decodeString(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> cnt;
        stack<string> p;
        string res,temp;
        int i=0,n;
        while(i<s.length()){
           // cout<<i<<endl;
            if(isdigit(s[i])){
                n=0;
                while(isdigit(s[i]))
                    n=n*10+(s[i++]-'0');
                cnt.push(n);
            }
            else if(s[i]=='['){
                p.push(temp);
                temp="";
                i++;
            }
            else if(s[i]==']'){
                res=p.top();
                p.pop();
                n=cnt.top();
                //cout<<res<<endl;
                cnt.pop();
                while(n--)
                    res.append(temp);
                temp=res;
                i+=1;
            }
            else
                temp.push_back(s[i++]);
        }
        return temp;
    }
};
        
        
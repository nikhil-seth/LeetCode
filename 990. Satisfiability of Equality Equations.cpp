// 990. Satisfiability of Equality Equations

class Solution {
public:
    vector<char> m;
    vector<int> s;
    int findset(int v){
        if(m[v]==v) return v;
        return m[v]=findset(m[v]);
    }
    bool equationsPossible(vector<string>& equations){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int a,b;
        m=vector<char>(26,'#');
        s=vector<int>(26);
        for(auto x:equations){
            a=x[0]-'a',b=x[3]-'a';
            if(m[a]=='#')
                m[a]=a,s[a]=1;
            if(m[b]=='#')
                m[b]=b,s[b]=1;
            if(x[1]=='='){
                a=findset(a);
                b=findset(b);
                if(a!=b){
                    if(s[a]<s[b])
                        swap(a,b);
                    m[b]=a;
                    s[a]+=s[b];
                }
            }
        }
        for(auto x:equations){
            if(x[1]=='!'){
                a=findset(x[0]-'a');
                b=findset(x[3]-'a');
                //cout<<a<<' '<<b<<endl;
                if(a==b)
                    return 0;
            }
        }
        return 1;
    }
};

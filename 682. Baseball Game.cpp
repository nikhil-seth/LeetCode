// 682. Baseball Game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

        vector<int> v;
        for(auto c:ops){
            if(c[0]=='+'){
                int a=v[v.size()-1]+v[v.size()-2];
                v.push_back(a);
            }
            else if(c[0]=='D')
                v.push_back(v[v.size()-1]*2);
            else if(c[0]=='C')
                v.pop_back();
            else{
                if(c[0]=='-')
                    v.push_back(stoi(c.substr(1))*-1);
                else
                    v.push_back(stoi(c));
            }
        }
        int sum=0;
        for(auto c:v)
            sum+=c;
        return sum;
    }
};

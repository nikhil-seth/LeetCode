// 399. Evaluate Division

class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>> &m,string start,const string &end,unordered_set<string> &visited){
        visited.insert(start);
        if(start==end)
            return 1.0;
        for(auto x:m[start]){
            if(visited.find(x.first)==visited.end()){
                double d=dfs(m,x.first,end,visited);
                if(d==-1.0)
                    continue;
                return (d*x.second);
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        unordered_map<string,vector<pair<string,double>>> m;
        for(int i=0;i<values.size();i+=1){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        double kt;
        vector<double> ans;
        for(auto q:queries){
            if(m.find(q[0])==m.end() || m.find(q[1])==m.end())
                kt=-1.0;
            else if(q[0]==q[1])
                kt=1.0;
            else{
                unordered_set<string> vis;
                kt=dfs(m,q[0],q[1],vis);
            }
            ans.push_back(kt);
        }
        return ans;
    }
};
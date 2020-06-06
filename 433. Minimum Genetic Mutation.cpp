// 433. Minimum Genetic Mutation

class Solution {
public:
    char d[4]={'A','C','G','T'};
    int minMutation(string start, string end, vector<string>& bank){
        // Trying out Single BFS
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_set<string> s(bank.begin(),bank.end());
        if(s.find(end)==s.end()) return -1;
        queue<string> q;
        q.push(start);
        int lvl=0;
        while(!q.empty()){
            lvl+=1;
            int ctr=q.size();
            while(ctr--){
                
                auto str=q.front();
                q.pop();
                s.erase(str);
                for(int i=0;i<8;i+=1){
                    string temp=str;
                    for(auto ch:d){
                        temp[i]=ch;
                        if(temp==end)
                            return lvl;
                        if(s.find(temp)!=s.end())
                            q.push(temp);
                    }
                }
            }
        }
        return -1;
    }
};

            
            
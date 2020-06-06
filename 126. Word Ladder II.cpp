// 126. Word Ladder II

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        if(s.find(endWord)==s.end()) return ans;
        q.push({beginWord});
        int lvl=1;
        int mlvl=INT_MAX;
        unordered_set<string> visited;// All elems used in this lvl are here, will be removed & will not be used again.
        while(!q.empty()){
            auto path=q.front();
            q.pop();
            if(path.size()>lvl){
                // Means new lvl h, toh remove elem.
                if(path.size()>mlvl)
                    break;
                else
                    lvl=path.size();
                for(auto t1:visited)
                    s.erase(t1);
                visited.clear();
            }
            auto last=path.back();
            for(int i=0;i<last.size();i+=1){
                string temp=last;
                for(int j=0;j<26;j+=1){
                    temp[i]='a'+j;
                    if(s.find(temp)!=s.end()){
                        auto np=path;
                        np.push_back(temp);    
                        visited.insert(temp);
                        if(temp==endWord){
                            mlvl=lvl;
                            ans.push_back(np);
                        }
                        else
                            q.push(np);
                    }
                }
            }
        }
        return ans;
    }
};
            
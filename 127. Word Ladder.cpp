// 127. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_set<string> s(wordList.begin(),wordList.end());
        unordered_set<string> head,tail;
        if(s.find(endWord)==s.end()) return 0;
        int ls=2;
        unordered_set<char> valid[beginWord.length()];
        for(int i=0;i<wordList.size();i+=1){
            for(int j=0;j<wordList[i].length();j+=1){
                valid[j].insert(wordList[i][j]);
            }
        }
        head.insert(beginWord);
        tail.insert(endWord);
        while(!head.empty() && !tail.empty()){
            if(head.size()>tail.size())
                swap(head,tail);
            // head is always smaller.
            unordered_set<string> temp;
            for(auto x:head){
                for(int i=0;i<x.length();i+=1){
                    char te=x[i];
                    for(auto k:valid[i]){
                        x[i]=k;
                        if(tail.find(x)!=tail.end())
                            return ls;
                        if(s.find(x)!=s.end()){
                            temp.insert(x);
                            s.erase(x);
                        }
                    }
                    x[i]=te;
                }
            }
            ls+=1;
            head.swap(temp);
        }
        return 0;
    }
};

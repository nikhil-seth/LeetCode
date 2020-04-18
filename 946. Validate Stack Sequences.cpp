// 946. Validate Stack Sequences
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        stack<int> s;
        int i,j;
        for(i=j=0;j<popped.size() && i<pushed.size();){
            if(s.empty())
                s.push(pushed[i++]);
            else if(s.top()==popped[j]){
                s.pop();
                j++;
            }
            else
                s.push(pushed[i++]);
        }
        while(j<popped.size() && !s.empty() && s.top()==popped[j]){
            s.pop();
            j++;
        }
        if(j<popped.size())
            return 0;
        return 1;
    }
};
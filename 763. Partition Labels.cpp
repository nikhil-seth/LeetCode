// 763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string S){
        vector<int> last(26);
        vector<int> ans;
        for(int i=0;i<S.length();i+=1)
            last[S[i]-97]=i;
        int i,j,k;
        for(i=0;i<S.length();){
            j=last[S[i]-97];
            for(k=i;k<=j;k+=1)
                j=max(j,last[S[k]-97]);
            ans.push_back(j-i+1);
            i=j+1;
        }
        return ans;
    }
};

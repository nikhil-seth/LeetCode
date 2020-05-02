// 771. Jewels and Stones

class Solution {
public:
    int numJewelsInStones(string J, string S){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<bool> vis(250,0);
        int ctr=0;
        for(auto c:J)
            vis[c]=1;
        for(auto c:S){
            if(vis[c])
                ctr+=1;
        }
        return ctr;
    }
};

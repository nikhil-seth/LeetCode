// 765. Couples Holding Hands

class Solution {
public:
    vector<int> parent;
    int findset(int v){
        if(parent[v]==v) return v;
        return parent[v]=findset(parent[v]);
    }

    int minSwapsCouples(vector<int>& row){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        parent=vector<int>(row.size());
        for(int i=0;i<row.size();i+=2){
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        int ctr=0,x,y;
        for(int i=0;i<row.size();i+=2){
            x=findset(i);
            y=findset(i+1);
            if(x!=y){
                ctr+=1;
                parent[x]=y;
            }
        }
        return ctr;
    }
};

        
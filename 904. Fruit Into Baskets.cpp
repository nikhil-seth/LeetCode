// 904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& tree){
        int i,j,ans,ctr=0,k=2;
        i=j=ans=0;
        vector<int> v(tree.size(),0);
        for(;j<tree.size();j+=1){
            if(!v[tree[j]]++) k-=1;
            while(k<0){
                if(!--v[tree[i++]]) k+=1;
                ctr-=1;
            }
            ctr+=1;
            ans=max(ans,ctr);
        }
        return ans;
    }
};

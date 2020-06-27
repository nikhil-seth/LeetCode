// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int tg=0,n=gas.size();
        for(int i=0,j;i<n;){
           // cout<<i<<endl;
            tg=0;
            j=i;
            do{
                tg+=gas[j]-cost[j];
                j+=1;
                j%=n;
                if(tg<0)
                    break;
            }while(j!=i);
            if(j==i){
                if(tg>=0) return i;
                i=j+1;
            }
            else if(j<i) return -1;
            else
                i=j;
        }
        return -1;
    }
};

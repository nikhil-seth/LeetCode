// 1387. Sort Integers by The Power Value
class Solution {
    int cmp[1001];
    int init(int i){
        if(i==1) return 0;
        if(i%2==0)
            return init(i/2)+1;
        else 
            return init(i*3+1)+1;
    }
public:
    Solution(){
        cmp[1]=0;
        for(int i=2;i<=1000;i+=1)
            cmp[i]=init(i);
    }
    int getKth(int lo, int hi, int k){
        vector<pair<int,int>> arr(hi-lo+1);
        for(int i=lo,j=0;i<=hi;i+=1)
            arr[j++]={cmp[i],i};
        sort(arr.begin(),arr.end());
        return arr[k-1].second;
    }
};

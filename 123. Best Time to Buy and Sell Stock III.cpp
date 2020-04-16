// 123. Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& arr){
        int n=arr.size();
        if(n<2)
            return 0;
        int b1,b2,s1,s2;
        b1=b2=INT_MIN;
        s1=s2=0;
        for(int i=0;i<n;i++){
            b1=max(b1,-arr[i]);
            s1=max(s1,b1+arr[i]);
            b2=max(b2,s1-arr[i]);
            s2=max(s2,b2+arr[i]);
        }
        return s2;
    }
};
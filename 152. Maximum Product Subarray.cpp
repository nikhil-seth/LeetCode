// 152. Maximum Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int maxe,mine,msf=INT_MIN;
        maxe=mine=1;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                maxe*=arr[i];
                mine=min(mine*arr[i],1);    // In Case if Mine is +ve toh BT h. 1*arr[i]=arr[i].
            }
            else if(arr[i]==0){
                mine=1;
                maxe=0;
            }
            else{
                int temp=maxe;
                maxe=mine*arr[i];
                mine=temp*arr[i];
            }
            msf=max(msf,maxe);
            if(maxe<=0)
                maxe=1;
        }
        return msf;
    }
};

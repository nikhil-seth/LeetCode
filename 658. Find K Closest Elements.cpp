// 658. Find K Closest Elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> v;
        int n=arr.size();
        if(!n) return v;
        int id=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=id-1,j=id;
        while(i>=0 && j<n && k>0){
            if((x-arr[i])<=(arr[j]-x))
                i--;
            else
                j++;
            k--;
        }
        if(i<0)
            j+=k;
        else
            i-=k;
        i+=1;
        while(i<j)
            v.push_back(arr[i++]);
        return v;
    }
};
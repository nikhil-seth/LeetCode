// 167. Two Sum II - Input array is sorted

static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target){
        vector<int> v(2);
        v[0]=0;
        v[1]=arr.size()-1;
        while(1){
            if(arr[v[0]]+arr[v[1]]==target)
                break;
            else if(arr[v[0]]+arr[v[1]]>target)
                v[1]-=1;
            else
                v[0]+=1;
        }
        v[0]+=1;
        v[1]+=1;
        return v;
    }
};

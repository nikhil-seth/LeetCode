// 75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums){
        // Counting Sort.
        vector<int> v(3,0);
        for(auto &x:nums){
            v[x]+=1;
        }
        int i=0;
        for(auto &x:nums){
            while(v[i]==0) i+=1;
            x=i;
            v[i]-=1;
        }
    }
};
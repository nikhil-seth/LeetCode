// 349. Intersection of Two Arrays
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> s;
        sort(nums1.begin(),nums1.end());
        for(auto c:nums2){
            if(binary_search(nums1.begin(),nums1.end(),c))
                s.insert(c);
        }
        vector<int> v;
        for(auto c:s)
            v.push_back(c);
        return v;
    }
};
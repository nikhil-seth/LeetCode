// 496. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        unordered_map<int,int> m;
        for(int u:nums1)
            m[u]=-1;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i])
                s.pop();
            if(!s.empty()){
                if(m.find(nums2[i])!=m.end())
                    m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int &x:nums1){
            x=m[x];
        }
        return nums1;
    }
};
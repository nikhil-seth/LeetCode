// 373. Find K Pairs with Smallest Sums

class Solution {
    struct X{
        int val,x,y;
        X(int a,int b,int c){
            val=a,x=b,y=c;
        }
        bool operator<(const X &ax) const{
            return val>ax.val;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        priority_queue<X> pq;
        vector<vector<int>> ans;
        int n=nums1.size(),m=nums2.size();
        if(!n || !m) return ans;
        for(int i=0;i<n;i+=1){
            pq.push(X(nums1[i]+nums2[0],i,0));
        }
        X xt(0,0,0);
        vector<int> v(2);
        while(!pq.empty() && k--){
            xt=pq.top();
            pq.pop();
            v[0]=nums1[xt.x],v[1]=nums2[xt.y];
            ans.push_back(v);
            if(xt.y<m-1){
                xt.y+=1;
                xt.val=nums1[xt.x]+nums2[xt.y];
                pq.push(xt);
            }
        }
        return ans;
    }
};
        
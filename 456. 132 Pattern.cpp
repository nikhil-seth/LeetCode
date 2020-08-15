// 456. 132 Pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=nums.size();
        if(!n) return 0;
        vector<int> mel(n);
        mel[0]=nums[0];
        for(int i=1;i<n;i+=1)
            mel[i]=min(mel[i-1],nums[i]);
        stack<int> s;
        for(int i=n-1;i>=0;i-=1){
            while(!s.empty() && s.top()<nums[i]){
                if(s.top()>mel[i]) return 1;
                s.pop();
            }
            s.push(nums[i]);
        }
        return 0;
    }
};

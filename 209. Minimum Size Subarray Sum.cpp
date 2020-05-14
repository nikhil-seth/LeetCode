// 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int cum = 0, res = INT_MAX, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= s) {
                return 1;
            }
            cum += nums[i];
            while (j<i && cum >= s) {
                res = min(res, i-j+1);
                cum -= nums[j];
                j++;
            }
        }
        return res==INT_MAX?0:res;
    }
};
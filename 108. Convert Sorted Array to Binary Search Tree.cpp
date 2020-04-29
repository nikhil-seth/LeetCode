// 108. Convert Sorted Array to Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *fn(vector<int> &nums,int l,int r){
        if(l>r)
            return nullptr;
        int mid=(l+r)/2;
        TreeNode *nn=new TreeNode(nums[mid]);
        if(l==r)
            return nn;
        nn->right=fn(nums,mid+1,r);
        nn->left=fn(nums,l,mid-1);
        return nn;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        return fn(nums,0,nums.size()-1);
    }
};

// 1367. Linked List in Binary Tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto io=[](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    vector<int> prefix(vector<int> arr){
        // Here we compute the reset table.
        vector<int> res(arr.size()+1);
        res[0]=res[1]=0;
        for(int i=2,j;i<=arr.size();i++){
            j=res[i-1];
            while(1){
                if(arr[j]==arr[i-1]){
                    res[i]=j+1;
                    break;
                }
                if(j==0){
                    res[i]=0;
                    break;
                }
                j=res[j];
            }
        }
        return res;
    }
    bool fn(TreeNode *root,int j,vector<int> &pi,vector<int> &arr){
        if(!root)
            return 0;
        //cout<<j<<' '<<root->val<<endl;
        while(j>0 && arr[j]!=root->val)
            j=pi[j];
        if(root->val==arr[j])
            j+=1;
        if(j==arr.size())
            return 1;
        return fn(root->left,j,pi,arr) || fn(root->right,j,pi,arr);
    }
    bool isSubPath(ListNode* head, TreeNode* root){
        if(!head)
            return 1;
        vector<int> pi,arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        pi=prefix(arr);
        return fn(root,0,pi,arr);
    }
};
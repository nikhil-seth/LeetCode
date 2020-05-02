// 449. Serialize and Deserialize BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    TreeNode *fn(vector<int> &v,int &i,int mi,int ma){
        if(i>v.size())
            return nullptr;
        if(v[i]>mi && v[i]<ma){
            TreeNode *x=new TreeNode(v[i]);
            i+=1;
            x->left=fn(v,i,mi,x->val);
            x->right=fn(v,i,x->val,ma);
            return x;
        }
        return nullptr;
    }
    string serialize(TreeNode* root){
        ostringstream out;
        stack<TreeNode*> s;
        while(1){
            while(root){
                s.push(root);
                out<<(to_string(root->val)+" ");
                root=root->left;
            }
            if(s.empty())
                break;
            root=s.top();
            s.pop();
            root=root->right;
        }
        //cout<<x<<endl;
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if(data.size()==0)
            return nullptr;
        istringstream s(data);
        vector<int> v;
        while(s){
            s>>data;
            v.push_back(stoi(data));
        }
        int i=0;
        return fn(v,i,INT_MIN,INT_MAX);
    }
};
    

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
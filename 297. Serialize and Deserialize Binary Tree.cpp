// 297. Serialize and Deserialize Binary Tree
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
    void ser(TreeNode *root,ostringstream &s){
        if(!root)
            s<<"# ";
        else{
            s<<(to_string(root->val)+" ");
            ser(root->left,s);
            ser(root->right,s);
        }
    }
    TreeNode *deser(istringstream &s){
        string x;
        s>>x;
        cout<<x;
        if(x=="#")
            return nullptr;
        TreeNode *root=new TreeNode(stoi(x));
        root->left=deser(s);
        root->right=deser(s);
        return root;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
     //   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        ostringstream s;
        ser(root,s);
        return s.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        istringstream in(data);
        return deser(in);
    }
        
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
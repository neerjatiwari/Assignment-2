
class Solution {
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        TreeNode* temp= root->left;
        root->left=root->right;
        root->right=temp;
        solve(root->left);
        solve(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};

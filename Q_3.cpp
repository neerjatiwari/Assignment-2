class Solution {
public:
vector<int> numbers;

void inorderpush(TreeNode* root){
    if(root==nullptr){
        return;
    }
    inorderpush(root->left);
    numbers.push_back(root->val);
    inorderpush(root->right);
}

bool isValidBST(TreeNode* root) {
    inorderpush(root);

    for(int i=0;i<numbers.size()-1;i++){
        if(numbers[i+1]<=numbers[i]){
            return false;
        }
    }
    return true;  
    }
};

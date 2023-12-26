class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return aux(root, -2147483649, 2147483648);
    }

    bool aux(TreeNode* root, long long int inf, long long int upper){
        std::cout << inf << std::endl;
        if(inf < root->val && upper > root->val){
            if(root->right == NULL && root->left == NULL)return true;
            if(root->right == NULL){
                return aux(root->left, inf, root->val);
            }
            if(root->left == NULL){
                return aux(root->right, root->val, upper);
            }
            return (aux(root->left, inf, root->val) && aux(root->right, root->val, upper));
        }
        return false;
    }

};
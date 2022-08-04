// https://binarysearch.com/problems/Maximum-Non-Adjacent-Tree-Sum

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int helper(Tree* root, bool takeit){
    if(root==nullptr) return 0;
    if(takeit) return root->val+helper(root->left,false)+helper(root->right,false);
    return max(helper(root->left,true),helper(root->left,false))+max(helper(root->right,true),helper(root->right,false));
}
int solve(Tree* root) {
    return max(helper(root,true),helper(root,false));
}

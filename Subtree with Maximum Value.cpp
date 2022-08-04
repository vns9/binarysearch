// https://binarysearch.com/problems/Subtree-with-Maximum-Value

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int ans=0;
int helper(Tree* root){
    if(root==nullptr) return 0;
    int leftsub = helper(root->left);
    int rightsub = helper(root->right);
    ans=max(ans, root->val+leftsub+rightsub);
    return root->val+leftsub+rightsub;
}
int solve(Tree* root) {
    helper(root);
    int retval=ans;
    ans=0;
    return retval;
}

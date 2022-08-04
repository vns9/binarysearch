// https://binarysearch.com/problems/Longest-Tree-Path

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
    int lef = helper(root->left);
    int rig = helper(root->right);
    ans=max(ans,lef+rig+1);
    return 1+max(lef,rig);
}
int solve(Tree* root) {
    helper(root);
    int retans=ans;
    ans=0;
    return retans;
}

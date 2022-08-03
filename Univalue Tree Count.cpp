// https://binarysearch.com/problems/Univalue-Tree-Count

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int ans=0;
bool traverse(Tree* curr){
    if(curr==nullptr) return true;
    bool leftsub = traverse(curr->left);
    bool rightsub = traverse(curr->right);
    if(!rightsub||!leftsub) return false;
    if(curr->left==nullptr && curr->right==nullptr){
        ans++;
        return true;
    }
    else if(curr->left==nullptr && curr->right!=nullptr){
        if(curr->val==curr->right->val){
            ans++;
            return true;
        }
        else return false;
    }
    else if(curr->right==nullptr && curr->left!=nullptr){
        if(curr->val==curr->left->val){
            ans++;
            return true;
        }
        else return false;
    }
    else{
        if(curr->left->val!=curr->right->val || curr->left->val!=curr->val ||curr->val!=curr->right->val){
            return false;
        }
        else{
            ans++;
            return true;
        }
    }
    return false;
}
int solve(Tree* root) {
    traverse(root);
    int retans=ans;
    ans=0;
    return retans;
}

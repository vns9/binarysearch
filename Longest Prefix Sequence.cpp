// https://binarysearch.com/problems/Longest-Prefix-Sequence

class TrieNode{
    public: 
        TrieNode *child[26] = {nullptr};
        bool isend=false;
        TrieNode(){};
};

void insert(string word, TrieNode* curr) {
    for(int i=0;i<word.size();i++){
        if(curr->child[word[i]-'a']==nullptr) curr->child[word[i]-'a'] = new TrieNode();
        curr=curr->child[word[i]-'a'];
        if(i+1==word.size()) curr->isend=true;
    }
}

int ans=1;

void traverse(TrieNode* curr, TrieNode* parent, int prevSequenceLength){
    if(curr==nullptr) return;
    int currLength = 0;
    if(curr->isend){
        currLength=1;
    }
    if(parent && parent->isend && curr->isend){
        currLength = prevSequenceLength+1;
        ans=max(ans,currLength);
    }
    for(auto nextPtr: curr->child){
        traverse(nextPtr, curr, currLength);
    }
}
int solve(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for(auto word: words) insert(word, root);
    traverse(root,nullptr,0);
    //cout<<"ans"<<" "<<ans;
    int retans=ans;
    ans=1;
    return retans;
}

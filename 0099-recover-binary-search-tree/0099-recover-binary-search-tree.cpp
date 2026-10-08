/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode* root, vector<TreeNode*>& v){
    if(root==nullptr) return ;
    insert(root->left,v);
    v.push_back(root);
    insert(root->right,v);
}
    void recoverTree(TreeNode* root) {
        if(root==nullptr)return;
        TreeNode* p=nullptr;
        TreeNode* q= nullptr;
        vector<TreeNode*> v;
        insert(root,v);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]->val>v[i+1]->val){
               if(!p){
                 p=v[i];
            }
            q=v[i+1];
        }}
        int temp;
        temp=q->val;
        q->val=p->val;
        p->val=temp;
        return;
    }
};
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
    void solve(TreeNode* root,TreeNode* &temp,TreeNode* &p,TreeNode* &q){
    if(root==nullptr) return;
    solve(root->left,temp,p,q);
    if(temp!=nullptr&&temp->val>root->val){
        if(!p) p=temp;
        q=root;
    }
    temp=root;
    solve(root->right,temp,p,q);
}
    void recoverTree(TreeNode* root) {   
        if (root==nullptr) return;
       TreeNode* temp =nullptr;
       TreeNode* p=nullptr;
       TreeNode* q=nullptr;
        solve(root,temp,p,q);
        if (p != nullptr && q != nullptr) {
            int temp2 = p->val;
            p->val = q->val;
            q->val = temp2;
        }
        return;
    }
};
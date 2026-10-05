/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void insert(TreeNode* root,vector<TreeNode*>& a,TreeNode* p){
    if(root==nullptr)return;
    TreeNode* temp =root;
    while(temp!=p){
        a.push_back(temp);
        temp = temp->val>p->val ? temp->left: temp->right;
    }
    a.push_back(temp);
    return;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        vector<TreeNode*> a;
        insert(root,a,p);
        vector<TreeNode*>b;
        insert(root,b,q);
        TreeNode* lca=nullptr;
        int n = a.size()<b.size() ? a.size():b.size();
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                lca = a[i];
            }
        }
        return lca;
    }
};
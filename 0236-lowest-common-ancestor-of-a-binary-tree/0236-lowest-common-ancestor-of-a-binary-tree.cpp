#include<cmath>
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
void insert(TreeNode* root,TreeNode* p,vector<TreeNode*>& v,bool& found){
    if(root == nullptr) return;
    if(root == p){
        v.push_back(root);
        found = true;
        return;
    }
    v.push_back(root);
    insert(root->right,p,v,found);
    insert(root->left,p,v,found);
    if(found) return;
    v.pop_back();
    return;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        bool b1 = false;
        bool b2 = false;
        insert(root, p , v1,b1);
        insert(root,q,v2,b2);
        TreeNode* lca = nullptr;
        int n=0;
        if(v1.size()<v2.size()) n = v1.size();
        else n = v2.size();
        for(int i=0;i<n;i++){
            if(v1[i]==v2[i]){
                lca = v1[i];
            }
        }
        return lca;
    }
};
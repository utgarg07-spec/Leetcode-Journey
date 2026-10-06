auto init = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minv = min(p->val,q->val);
        int maxv= max(p->val,q->val);
        while(root){
            if(root->val>maxv) root = root->left;
            else if(root->val<minv) root=root->right;
           else{
            return root;
           }
        }
        return nullptr;
    }
};
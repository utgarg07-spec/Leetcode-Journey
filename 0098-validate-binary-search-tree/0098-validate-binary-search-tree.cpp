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
void solve(TreeNode* root,bool& check,long long& a){
    if(root==nullptr) return;
    if(!check) return;
    solve(root->left,check,a);
    if(!check) return;
        if(a<root->val) {
            check=true;
            a=root->val;
            }
        else {
            check=false;
            return;
        }
    solve(root->right,check,a);
}
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        if(root->left==nullptr&&root->right==nullptr) return true;
        bool check=true;
        long long a=LLONG_MIN;
        solve(root,check,a);
        return check;
    }
};
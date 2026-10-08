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
void solve(TreeNode* root,long long& temp,bool& check){
    if(root==nullptr) return;
    if(!check) return;
    solve(root->left,temp,check);
    if(!check) return;
    if(root->val>temp) temp=root->val;
    else{
        check=false;
        return;
    }
    solve(root->right,temp,check);
}
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        if(root->left==nullptr&&root->right==nullptr) return true;
       bool  check =true;
       long long temp= LLONG_MIN;
        solve(root,temp,check);
        return check;
    }
};
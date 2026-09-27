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
void solve(TreeNode* root,int sum, bool& ans,int target){
    if(root == nullptr ) return;
    sum+= root->val;
    if(root->left==NULL && root->right==NULL){
        if(sum == target){
            ans = true;
            return;
        }
    }
    solve(root->left,sum,ans,target);
    solve(root->right,sum,ans,target);
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans =false;
        int sum=0;
        solve(root,sum,ans,targetSum);
        return ans;
    }
};
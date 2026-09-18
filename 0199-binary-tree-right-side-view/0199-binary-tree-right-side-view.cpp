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
void depthCheck(TreeNode* root, int depth,vector<int>& a){
    if(root==nullptr) return;
    if(depth==a.size()){
        a.push_back(root->val);
    }
    depthCheck(root->right,depth+1,a);
    depthCheck(root->left,depth+1,a);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        depthCheck(root,0,ans);
        return ans;
    }
};
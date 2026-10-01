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
void calcPath(TreeNode* root, int target, int& count,long long sum){
    if(root == nullptr) return;
    
    sum= sum+root->val;
    if(sum==target) count++;
    calcPath(root->left,target,count,sum);
    calcPath(root->right,target,count,sum);
}
void solve(TreeNode* root,int& count,int target){
    if(root==nullptr) return;
    long long sum=0;
    calcPath(root,target,count,sum);
    solve(root->left,count,target);
    solve(root->right,count,target);
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int count=0;
        solve(root,count,targetSum);
        return count;
    }
};
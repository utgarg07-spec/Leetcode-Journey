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
void solve(TreeNode* root, string path,vector<string>& ans){
    if(root == nullptr) return;
    path+=to_string(root->val);
    if(root->left==NULL && root->right == NULL){
        ans.push_back(path);
        return;
    }
    solve(root->left,path,ans);
    solve(root->right,path,ans);
}
    int sumNumbers(TreeNode* root) {
        vector<string> ans;
        solve(root,"",ans);
        int sum=0;
        for(auto x: ans){
            sum+= stoi(x);
        }
        return sum;
    }
};
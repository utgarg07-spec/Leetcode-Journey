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
void store(TreeNode* root, vector<int>& values){
    if(root==nullptr) return;
    store(root->left,values);
    store(root->right,values);
    values.push_back(root->val);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        store(root,v);
        sort(v.begin(),v.end());
        return v[k-1];
    }
};
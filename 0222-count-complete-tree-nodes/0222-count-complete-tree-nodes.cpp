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
int rightMostHeight(TreeNode* root){
    if(root == nullptr) return 0;
    int count=0;
    while(root!=nullptr){
        count++;
        root=root->right;
    }
    return count;
}
int leftMostHeight(TreeNode* root){
    if(root == nullptr) return 0;
    int count=0;
    while(root!=nullptr){
        count++;
        root=root->left;
    }
    return count;
}
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh = leftMostHeight(root);
        int rh = rightMostHeight(root);
        if(lh == rh){
            return (1 << lh) - 1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};
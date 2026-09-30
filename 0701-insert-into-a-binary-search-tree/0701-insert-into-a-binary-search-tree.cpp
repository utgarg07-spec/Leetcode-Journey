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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root==nullptr){
            root = newNode;
            return root;
        }
        TreeNode* temp = root;
        TreeNode* temp2 = nullptr;
        while(temp){
            temp2 = temp;
            temp = val>temp->val? temp->right:temp->left;
        }

        if(temp2->val<val){
            temp2->right = newNode;
        }
        else{
            temp2->left = newNode;
        }
        return root;
    }
};
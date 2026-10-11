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
TreeNode* minVal(TreeNode* root){
    if(root==nullptr) return root;
    TreeNode* curr=root;
    while(curr->left!=nullptr){
        curr=curr->left;
    }
    return curr;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            //one or no child
            if(root->left==nullptr||root->right==nullptr){
                TreeNode* temp = root->left?root->left:root->right;
            //no child
            if(temp==nullptr){
                temp =root;
                root=nullptr;
            }
            //one child
            else{
                *root=*temp;
            }
            delete temp;
        }
        else{
            //2 children
            TreeNode* temp = minVal(root->right);
            root->val  = temp->val;
            root->right=deleteNode(root->right,temp->val);
           }
      }
      return root;
    }
};
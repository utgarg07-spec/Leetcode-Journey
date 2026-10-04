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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val==key){
            if(root->left==nullptr&&root->right==nullptr){
                TreeNode* temp = root;
                delete temp;
                root=nullptr;
                return root;
            }
            if(root->left==nullptr&&root->right!=nullptr){
                TreeNode* temp=root;
                root=temp->right;
                delete temp;
                return root;
            }
            if(root->right==nullptr&&root->left!=nullptr){
                TreeNode* temp=root;
                root=temp->left;
                delete temp;
                return root;
            }
            TreeNode* temp=root;
            TreeNode* temp3 = temp->left;
            TreeNode*  temp4 = temp->right;
            TreeNode* temp5 = nullptr;
            while(temp4){
                temp5=temp4;
                temp4 = temp4->left;
            } 
            temp5->left = temp3;
            temp->left = nullptr;
            root=temp->right;
            temp->right=nullptr;
            delete temp;
            return root;
        }
        TreeNode* temp = root;
        bool flag = false;
        TreeNode* temp2=nullptr;
        while(temp){
             if(temp->val==key) {
                flag = true;
                break;
            }
            temp2 = temp;
            temp = temp->val>key? temp->left:temp->right;
        }
        if(!flag) return root;
        if(temp->left==nullptr && temp->right==nullptr){
            if(temp2->right==temp) temp2->right = nullptr;
            else temp2->left= nullptr;
             delete temp;
             return root;
        }
        if(temp->right == nullptr&&temp->left!=nullptr) {
            if(temp2->right==temp){
                temp2->right = temp->left;
                temp->left=nullptr;
                delete temp;
            }
            else{
                temp2->left=temp->left;
                temp->left=nullptr;
                delete temp;
            }
            return root;
        }
        if(temp->left == nullptr&&temp->right!=nullptr) {
            if(temp2->right==temp){
                temp2->right = temp->right;
                temp->right=nullptr;
                delete temp;
            }
            else{
                temp2->left=temp->right;
                temp->right=nullptr;
                delete temp;
            }
            return root;
        }
        if(temp2->right==temp){
            TreeNode* temp3 = temp->left;
            TreeNode*  temp4 = temp->right;
            TreeNode* temp5 = nullptr;
            while(temp4){
                temp5=temp4;
                temp4 = temp4->left;
            } 
            temp5->left = temp3;
            temp->left = nullptr;
            temp2->right=temp->right;
            temp->right=nullptr;
            delete temp;
        }
        else{
            TreeNode* temp3 = temp->left;
            TreeNode*  temp4 = temp->right;
            TreeNode* temp5 = nullptr;
            while(temp4){
                temp5=temp4;
                temp4 = temp4->left;
            } 
            temp5->left = temp3;
            temp->left = nullptr;
            temp2->left=temp->right;
            temp->right=nullptr;
            delete temp;
        }
        return root;
    }
};
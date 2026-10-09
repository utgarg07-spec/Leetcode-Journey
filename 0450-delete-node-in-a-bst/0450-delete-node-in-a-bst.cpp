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

TreeNode* maxVal(TreeNode* root){
    if(root==nullptr) return root;
    TreeNode* temp=root;
    TreeNode* par = nullptr;
    while(temp){
        par=temp;
        temp=temp->right;
    }
    return par;
}

TreeNode* maxValPar(TreeNode* root){
    if(root==nullptr) return root;
    TreeNode* temp=root;
    TreeNode* par = nullptr;
    while(temp->right!=nullptr){
        par=temp;
        temp=temp->right;
    }
    return par;
}

void del(TreeNode* root,TreeNode* temp,TreeNode* parent_temp){
    if(temp->left==nullptr&&temp->right==nullptr){
        if(parent_temp->left==temp){
            parent_temp->left=nullptr;
        }
        else{
            parent_temp->right=nullptr;
        }
        delete temp;
    }
    else if((temp->left==nullptr&&temp->right!=nullptr)||(temp->right==nullptr&&temp->left!=nullptr)){
        if(parent_temp->left==temp&&temp->right!=nullptr){
            parent_temp->left=temp->right;
            temp->right=nullptr;
            delete temp;
        }
        else if(parent_temp->left==temp&&temp->left!=nullptr){
            parent_temp->left=temp->left;
            temp->left=nullptr;
            delete temp;
        }
        else if(parent_temp->right==temp&&temp->left!=nullptr){
            parent_temp->right=temp->left;
            temp->left=nullptr;
            delete temp;
        }
        else{
            parent_temp->right=temp->right;
            temp->right=nullptr;
            delete temp;
        }
    }
    else{  
        TreeNode* lar = nullptr;
        TreeNode* parLar = nullptr;
        
        if (temp->left->right == nullptr) {
            lar = temp->left;
            parLar = temp;
        } else {
            lar = maxVal(temp->left);
            parLar = maxValPar(temp->left);
        }
        
        temp->val = lar->val;
        if (parLar == temp) {
            parLar->left = lar->left;
        } else {
            parLar->right = lar->left;
        }
        lar->left = nullptr;
        delete lar;
    }
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return root;
    TreeNode* temp=root;
    TreeNode* parent_temp=nullptr;
    while(temp!=nullptr){
        if(temp->val==key) break;
        parent_temp=temp;
        temp = key>temp->val? temp->right:temp->left;
    }
    if(temp==nullptr) return root;
    if(parent_temp!=nullptr) del(root,temp,parent_temp);
    else{
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if(root->left==nullptr&&root->right!=nullptr){
            TreeNode* temppp=root;
            root=root->right;
            temppp->right=nullptr;
            delete temppp;
        }
        else if(root->right==nullptr&&root->left!=nullptr){
            TreeNode* temppp=root;
            root=root->left;
            temppp->left=nullptr;
            delete temppp;
        }
        else {
            TreeNode* lar = nullptr;
            TreeNode* parLar = nullptr;
            
            if (root->left->right == nullptr) {
                lar = root->left;
                parLar = root;
            } else {
                lar = maxVal(root->left);
                parLar = maxValPar(root->left);
            }
            
            root->val = lar->val;
            
            if (parLar == root) {
                parLar->left = lar->left;
            } else {
                parLar->right = lar->left;
            }
            lar->left = nullptr;
            delete lar;
        }
    }
    return root; 
}
};
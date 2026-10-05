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
/*void solve(TreeNode* root, bool& check){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr&&root->right==nullptr) return;
    if(root->left==nullptr&&root->right!=nullptr){
        check = root->right->val>root->val? true:false;
        if(!check) return;
    }
   else if(root->right==nullptr&&root->left!=nullptr){
        check = root->left->val<root->val? true:false;
        if(!check) return;
    }
   else if(root->val> root->left->val && root->val<root->right->val) check = true;
    else{
        check =false;
        return;
    }
    solve(root->left,check);
    solve(root->right, check);
}*/
void solve(TreeNode* root,vector<int>& store){
    if(root==nullptr) return;
    solve(root->left,store);
    store.push_back(root->val);
    solve(root->right,store);
}
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        if(root->left==nullptr&&root->right==nullptr) return true;
        vector<int> v;
        solve(root,v);
        bool check = true;
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]){
                check=false;
                break;
            }
        }
        return check;
    }
};
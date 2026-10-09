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
void solve(TreeNode* root,bool& is_seen, bool& check){
    if(root==nullptr) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr==nullptr) {
            is_seen=true;
        }
        else{
            if(is_seen){
                check=false;
                return;
            }
        q.push(curr->left);
        q.push(curr->right);}
    }
}
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr) return true;
        bool is_seen=false;
        bool check = true;
        solve(root,is_seen,check);
        return check;
    }
};
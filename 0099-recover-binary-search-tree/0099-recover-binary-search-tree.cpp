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
void morris(TreeNode* root, TreeNode* &p,TreeNode*& q,TreeNode* &visited){
    if(root==nullptr)return;
    TreeNode* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            if(visited!=nullptr&&visited->val>curr->val){
                if(p==nullptr){
                        p=visited;
                    }
                    q=curr;
            }
            visited = curr;
            curr=curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right&&prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                if(visited!=nullptr&&visited->val>curr->val){
                    if(p==nullptr){
                        p=visited;
                    }
                    q=curr;
                }
                visited=curr;
                curr = curr->right;
            }
        }
    }

}
    void recoverTree(TreeNode* root) {   
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr) return;
        TreeNode* p=nullptr;
        TreeNode* q =nullptr;
        TreeNode* visited=nullptr;
        morris(root,p,q,visited);
        if(p!=nullptr&&q!=nullptr){
        int temp = p->val;
        p->val = q->val;
        q->val= temp;}
        return;
    }
};
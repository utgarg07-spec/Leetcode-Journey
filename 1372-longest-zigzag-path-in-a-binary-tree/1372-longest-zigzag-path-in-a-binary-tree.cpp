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
void solve(TreeNode* root, int& ans){
    if(root == NULL ) return;
    TreeNode* temp1 = root;
    TreeNode* temp2 = root;
    int sum1=0;
    int sum2=0;
    while(temp1!=NULL){
        if(temp1->left!=NULL){
            temp1=temp1->left;
            sum1+=1;
        }
        else{
            break;
        }
        if(temp1->right!=NULL){
            temp1=temp1->right;
            sum1+=1;
        }
        else{
            break;
        }
    }
    if(sum1>ans){
        ans=sum1;
    }
    while(temp2!=NULL){
        if(temp2->right!=NULL){
            temp2=temp2->right;
            sum2+=1;
        }
        else{
            break;
        }
        if(temp2->left!=NULL){
            temp2=temp2->left;
            sum2+=1;
        }
        else{
            break;
        }
    }
    if(sum2>ans){
        ans=sum2;
    }
    solve(root->left,ans);
    solve(root->right,ans);
}
    int longestZigZag(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
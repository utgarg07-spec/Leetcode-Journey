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
    int solve(TreeNode* root,int& cnt){
        if(root==NULL) return 2;
       int a= solve(root->left,cnt);
        int b= solve(root->right,cnt);
        if(a==0||b==0){
            cnt++;
            return 1;
        }
        if(a==1||b==1){
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        int cnt=0;
        int a =solve(root,cnt);
        if(a==0) cnt++;
        return cnt;
    }
      /*int solve(TreeNode* root, int& cnt) {
        if (root == nullptr) return 2;
        
        int a = solve(root->left, cnt);
        int b = solve(root->right, cnt);
        
        if (a == 0 || b == 0) {
            cnt++;
            return 1;
        }
        
        if (a == 1 || b == 1) {
            return 2;
        }
        
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        int cnt = 0;
        
        if (solve(root, cnt) == 0) {
            cnt++;
        }
        
        return cnt;
    }*/
};
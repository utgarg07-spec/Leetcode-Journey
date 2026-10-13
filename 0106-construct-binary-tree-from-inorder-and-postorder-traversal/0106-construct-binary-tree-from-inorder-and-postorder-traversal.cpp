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
int search(vector<int>& inorder, int start, int end,int key){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key) return i;
    }
    return -1;
}
TreeNode* build(vector<int>& post,vector<int>& in, int start,int end, int& index){
    if(start>end) return nullptr;
    TreeNode* root= new TreeNode(post[index--]);
    if(start==end) return root;
    int pos = search(in,start,end,root->val);
    root->right=build(post,in,pos+1,end,index);
    root->left= build(post,in,start,pos-1,index);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()!=inorder.size()) return nullptr;
        int n=inorder.size();
        int index=n-1;
        TreeNode* root=build(postorder,inorder,0,n-1,index);
     return root;
    }
};
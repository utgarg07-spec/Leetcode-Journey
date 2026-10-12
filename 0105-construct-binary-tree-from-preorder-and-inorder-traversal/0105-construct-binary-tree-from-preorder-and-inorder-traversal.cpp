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
int search(vector<int> inorder, int start, int end,int key){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key) return i;
    }
    return -1;
}
TreeNode* build(vector<int> pre,vector<int> in, int start,int end, int& index){
    if(start>end) return nullptr;
    TreeNode* root= new TreeNode(pre[index++]);
    if(start==end) return root;
    int pos = search(in,start,end,root->val);
    root->left= build(pre,in,start,pos-1,index);
    root->right=build(pre,in,pos+1,end,index);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()) return nullptr;
        int n=inorder.size();
        int index=0;
        TreeNode* root=build(preorder,inorder,0,n-1,index);
     return root;}
};
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
    vector<int>inorder;
    void inorderTraversal(TreeNode* root){
        if(root==NULL) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    TreeNode * build(int left,int right){
        if(left>right) return NULL;

        int mid=(left+right)/2;
        TreeNode * root=new TreeNode(inorder[mid]);

        root->left=build(left,mid-1);
        root->right=build(mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
       inorderTraversal(root);
       return build(0,inorder.size()-1);
    }
};
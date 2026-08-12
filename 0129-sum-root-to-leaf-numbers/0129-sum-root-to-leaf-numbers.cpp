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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>>st;
        st.push({root,root->val});
        int ans=0;
        while(!st.empty()){
          TreeNode* node=st.top().first;
          int num=st.top().second;

          st.pop();
          if(node->left==NULL&&node->right==NULL){
            ans+=num;
          }

          if(node->left){
            int currNum=num*10+node->left->val;
            st.push({node->left,currNum});
          }
          if(node->right){
            int currNum=num*10+node->right->val;
            st.push({node->right,currNum});
          }
        }
       return ans;
    }
};
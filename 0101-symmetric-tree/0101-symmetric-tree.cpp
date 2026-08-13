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
    bool isSymmetric(TreeNode* root) {
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({root->left,root->right});
        while(!st.empty()){
            TreeNode* Left=st.top().first;
            TreeNode* Right=st.top().second;
            st.pop();
            if(Left==NULL&&Right==NULL) continue;
            if(Left==NULL||Right==NULL) return false;
            if(Left->val!=Right->val) return false;
            st.push({Left->left,Right->right});
            st.push({Left->right,Right->left});
        }
        return true;
    }
};
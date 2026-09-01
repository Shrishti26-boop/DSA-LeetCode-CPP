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
    vector<int>PBTsize;
    pair<bool,int>dfs(TreeNode * root){
        if(root==NULL) return{true,0};
        auto left=dfs(root->left);
        auto right=dfs(root->right);

        if(left.first && right.first && left.second==right.second){
            int size=left.second+right.second+1;
            PBTsize.push_back(size);
            return {true,size};
        }
        return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
       dfs(root); 
       sort(PBTsize.begin(),PBTsize.end(),greater<int>());
       if(k>PBTsize.size()){
       return -1;
       }
       return PBTsize[k-1];
    }
};
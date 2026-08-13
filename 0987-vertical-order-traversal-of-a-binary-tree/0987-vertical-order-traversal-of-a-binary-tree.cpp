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
    vector<tuple<int,int,int>>nodes;
    void dfs(TreeNode* root,int row,int col)
{
    if(root==NULL) return ;
    nodes.push_back({root->val,row,col});
    dfs(root->left,row+1,col-1);
    dfs(root->right,row+1,col+1);

}    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root,0,0);
        sort(nodes.begin(),nodes.end(),
        [](auto &a,auto &b){
            if(get<2>(a)!=get<2>(b))
               return get<2>(a) < get<2>(b);

            if(get<1>(a)!=get<1>(b))
               return get<1>(a) < get<1>(b);
          return get<0>(a) < get<0>(b);
        });
        int currentCol=INT_MIN;

        for(auto &t:nodes){
            int value=get<0>(t);
            int row=get<1>(t);
            int col=get<2>(t);

            if(col!=currentCol){
                ans.push_back({});
                currentCol=col;
            }
            ans.back().push_back(value);
        }
        return ans;
    }
};
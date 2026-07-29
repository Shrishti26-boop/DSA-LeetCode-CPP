class Solution {
public:
    void getallSubset(vector<int>& nums,vector<int>& ans,vector<vector<int>> &allSubsets,int i){
        if(i==nums.size()){
            allSubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getallSubset(nums,ans,allSubsets,i+1);
        ans.pop_back();
        getallSubset(nums,ans,allSubsets,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>>allSubsets;
        getallSubset(nums,ans,allSubsets,0);
        return allSubsets;
    }
};
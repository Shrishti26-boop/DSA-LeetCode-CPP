class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for(int x:nums){
            if(x>=0){
                pos.push_back(x);
            }
            else{
                neg.push_back(x);
            }
        }
        int i=0;
        int j=0;
        while(i<pos.size()&&j<neg.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }
       return ans;
    }
};
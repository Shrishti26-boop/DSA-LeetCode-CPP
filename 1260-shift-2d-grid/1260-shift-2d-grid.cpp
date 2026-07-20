class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n=grid[0].size();
        int size=m*n;
        vector<int>nums(size);
        int c=0;
        
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[i*n+j]=grid[i][j];
            }
        }
        vector<int> shifted(size);
      
        for (int i = 0; i < size; i++) {
            shifted[(i + k) % size] = nums[i];
        }

        
        for (int i = 0; i < size; i++) {
            grid[i / n][i % n] = shifted[i];
        }
        
    return grid;

    }
};
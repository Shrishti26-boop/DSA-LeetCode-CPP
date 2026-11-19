class Solution {
public:
    void dfs(int src,vector<int>&vis,vector<vector<int>>& rooms){
        vis[src]=1;
        for(int v:rooms[src]){
            if(!vis[v]){
                dfs(v,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n=rooms.size();
      vector<int>vis(n,0);
      dfs(0,vis,rooms);
      for(int i=0;i<n;i++){
        if(!vis[i]) return false;
      }
      return true;
    }
};
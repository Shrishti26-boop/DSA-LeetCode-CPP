class Solution {
public:
    bool dfs(vector<vector<int>>&adj, int u, int destination,vector<int>&vis){
        if(u==destination) return true;

        vis[u]=1;
        for(int v:adj[u]){
           if(!vis[v]){
            if(dfs(adj,v,destination,vis))
            return true;
           } 
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<vector<int>>adj(n);

       for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
       } 
       vector<int>vis(n,0);
       return dfs(adj,source,destination,vis);
    }
};
class Solution {
public:
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ls){
    vis[node]=1;
    ls.push_back(node);
    for(int it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j ){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        vector<vector<int>> ls;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> temp;
                dfs(i,adj,vis,temp);
                ls.push_back(temp);
            }
        }
        int cnt = ls.size();
        return cnt;
    }
};
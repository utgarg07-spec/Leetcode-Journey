class Solution {
public:
void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){
    if(i<0||i>=n||j<0||j>=m||grid[i][j]==0||vis[i][j]==1) return;
    vis[i][j]=1;
    dfs(i+1,j,grid,vis,n,m);
    dfs(i-1,j,grid,vis,n,m);
    dfs(i,j+1,grid,vis,n,m);
    dfs(i,j-1,grid,vis,n,m);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(i==0||i==n-1||j==0||j==m-1){
                        if(grid[i][j]==1&&!vis[i][j]) dfs(i,j,grid,vis,n,m);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
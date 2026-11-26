class Solution {
public:
void dfs(int row,int column,vector<vector<int>>& image,vector<vector<int>>& vis,int color,int c,int n,int m){
    if(row<0||row>=n||column<0||column>=m||vis[row][column]==1||image[row][column]!=c) return;
    if(vis[row][column]==0){
        vis[row][column]=1;
        image[row][column]=color;
    }
    dfs(row+1,column,image,vis,color,c,n,m);
    dfs(row,column+1,image,vis,color,c,n,m);
    dfs(row-1,column,image,vis,color,c,n,m);
    dfs(row,column-1,image,vis,color,c,n,m);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int c= image[sr][sc];
        dfs(sr,sc,image,vis,color,c,n,m);
        return image;
    }
};
class Solution {
public:
    void DFS(vector<vector<int>>&image,int i,int j,int r,int c,int color,int oldcolor){
        if(i<0 || j<0 || i>=r || j>=c || image[i][j]!=oldcolor || image[i][j]==color){
            return;
        }
        image[i][j]=color;
        DFS(image,i,j+1,r,c,color,oldcolor);
        DFS(image,i-1,j,r,c,color,oldcolor);
        DFS(image,i,j-1,r,c,color,oldcolor);
        DFS(image,i+1,j,r,c,color,oldcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        DFS(image,sr,sc,r,c,color,image[sr][sc]);
        return image;
    }
};
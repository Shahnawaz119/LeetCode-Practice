class Solution {
public:
    vector<int> getNSR(vector<int> &height){
        int n=height.size();
        stack<int> st;
        vector<int> NSR(n);
        st.push(n-1);
        NSR[n-1]=n;
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                NSR[i]=n;
            }else{
                NSR[i]=st.top();
            }
            st.push(i);
        }
        return NSR;
    }

    vector<int> getNSL(vector<int> &height){
        int n=height.size();
        stack<int> st;
        vector<int> NSL(n);
        NSL[0]=-1;
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                NSL[i]=-1;
            }else{
                NSL[i]=st.top();
            }
            st.push(i);
        }
        return NSL;
    }
    int findArea(vector<int> &height){
        int n=height.size();
        vector<int> NSR=getNSR(height);
        vector<int> NSL=getNSL(height);
        vector<int> width(n);
        for(int i=0; i<n; i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int maxArea=0;
        for(int i=0; i<n; i++){
            int currArea=width[i]*height[i];
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> height(n);
        for(int i=0; i<n; i++){
            height[i]=(matrix[0][i]=='1') ? 1 : 0;
        }
        int maxArea=findArea(height);
        for(int row=1; row<m; row++){
            for(int col=0; col<n; col++){
                if(matrix[row][col]=='0'){
                    height[col]=0;
                }else{
                    height[col]+=1;
                }
            }
            maxArea=max(maxArea,findArea(height));
        }
        return maxArea;
    }
};
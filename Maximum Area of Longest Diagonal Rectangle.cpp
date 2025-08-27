class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions){

        int n = dimensions.size();

        int maxDiag = 0;
        int maxArea = 0;


        for(int i=0; i<n; i++){
            int l = dimensions[i][0];
            int b = dimensions[i][1];

            int diag = l*l + b*b;
            int area = l*b;

            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }
            else if(diag == maxDiag){
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

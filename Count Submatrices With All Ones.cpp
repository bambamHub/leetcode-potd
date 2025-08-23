class Solution {
public:
    int OneDArrCnt(vector<int> &vec){
        int consec = 0;
        int subCnt = 0;

        for(int &val : vec){
            if(val==1){
                consec++;
                subCnt += consec;
            }
            else{
                consec = 0;
            }
        }
        return subCnt;
    }
    int numSubmat(vector<vector<int>>& mat){

        int n = mat.size();
        int m = mat[0].size();

        int res = 0;

        for(int startRow = 0; startRow<n; startRow++){

            vector<int> vec(m, 1);
            for(int endRow = startRow; endRow<n; endRow++){
                for(int col=0; col<m; col++){
                    vec[col] = vec[col] & mat[endRow][col];
                }
                res += OneDArrCnt(vec);
            }
        }
        return res;
        
    }
};

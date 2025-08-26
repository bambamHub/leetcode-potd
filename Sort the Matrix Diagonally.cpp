class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat){

        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        for(auto &[key, vec] : mp){
            sort(vec.rbegin(), vec.rend());
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int key = i - j;
                mat[i][j] = mp[key].back();
                mp[key].pop_back();
            }
        }
        return mat;
    }
};

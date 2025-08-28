class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it : mp){
            if(it.first < 0){
                sort(it.second.rbegin(), it.second.rend());
            }
            else{
                sort(it.second.begin(), it.second.end());
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int key = i-j;
                grid[i][j] = mp[key].back();
                mp[key].pop_back();
            }
        }
        return grid;
        
    }
};

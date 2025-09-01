class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val){

        for(int i=0; i<9; i++){
            
            // row check
            if( i != col && board[row][i]==val){
                return false;
            }

            // col check
            if(i != row && board[i][col]==val){
                return false;
            }

            // 3*3 matrix check
            int subRow = 3*(row/3) + (i/3);
            int subCol = 3*(col/3) + (i%3);
            if( subRow!=row && subCol!=col && board[subRow][subCol]==val){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board){

        int n = board.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.'){
                    char val = board[i][j];
                    if(!isSafe(i, j, board, val)){
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

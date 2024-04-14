bool isSafe(vector<vector<int>> &board, int row, int col){

    for(int i = 0; i < row; i++){
        if(board[i][col]) return false;
    }

    for(int i = row, j = col; i >= 0 and j >= 0; i--, j--){
        if(board[i][j]) return false;
    }

    for(int i = row, j = col; i >= 0 and j < board.size(); i--, j++){
        if(board[i][j]) return false;
    }

    return true;

}

bool NQueen(vector<vector<int>> &board, int row){
    if(row >= board.size()){
        return true;
    }

    for(int i = 0; i < board.size(); i++){
        if(isSafe(board, row, i)){
            board[row][i] = 1;

            if(NQueen(board, row+1)){
                return true;
            }

            board[row][i] = 0;
        }
    }
    return false;
}

void solve(){
  vector<vector<int>> board = { { 0, 0, 0, 0 },
                                { 0, 0, 0, 0 },
                                { 0, 0, 0, 0 },
                                { 0, 0, 0, 0 } 
                              }; 
  if(!NQueen(board, 0)){
    cout << "Solution does not Exist";
  }
  else{
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
  }
}
bool NQueen(vector<vector<int>> &board, int row, vector<bool> &cols, vector<bool> &ndiag, vector<bool> &rdiag)
{

    if (row == board.size())
    {
        return true;
    }

    for (int col = 0; col < board.size(); col++)
    {
        if (!cols[col] and !ndiag[col + row] and !rdiag[row - col + board.size() - 1])
        {

            board[row][col] = 1;
            cols[col] = ndiag[col + row] = rdiag[row - col + board.size() - 1] = 1;

            if (NQueen(board, row + 1, cols, ndiag, rdiag))
            {
                return true;
            }

            board[row][col] = 0;
            cols[col] = ndiag[col + row] = rdiag[row - col + board.size() - 1] = 0;
        }
    }
    return false;
}

void solve()
{
    vector<vector<int>> board = {{0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0}};
    int n = board.size();
    vector<bool> cols(n, 0);
    vector<bool> ndiag(2 * n - 1, 0);
    vector<bool> rdiag(2 * n - 1, 0);

    if (!NQueen(board, 0, cols, ndiag, rdiag))
    {
        cout << "Solution does not Exist";
    }
    else
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}

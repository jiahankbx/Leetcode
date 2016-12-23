class Solution {  
private:  
    bool isOver;  //是否已经找到一个正确解。  
  
public:  
    void dfs (vector<vector<char> > &board, int i, int j, int n ) {  
        //if (this->isOver) return;  
        if (j >= n) {  
            dfs(board, i+1, 0, n);  
        } else if (i == n){  
            this->isOver = true;  
            return ;  
        } else if (board[i][j] != '.'){  
            dfs(board, i, j+1, n);  
        } else {  
            for (int k = 1; k <= n; ++k){  
                board[i][j] = (char)('0' + k);  
                if (isValid(board, i, j, n)){  
                    dfs(board, i, j+1 , n);  
                }  
                if (this->isOver) return;  //找到一个解救跳出，防止遍历整个search tree  
                    board[i][j] = '.';  
            }  
        }  
        return ;  
    }  
    bool isValid(vector<vector<char>> &board, int i , int j, int n) {  
        for (int index = 0; index < n; ++index){  
            if (index != j && board[i][index] == board[i][j]) {  
                return false;  
            }  
        }  
  
        for (int index = 0; index < n; ++index){  
            if (index != i && board[index][j] == board[i][j]) {  
                return false;  
            }  
        }  
  
        int index_i = i / 3;  
        int index_j = j / 3;  
          
        for (int x = index_i * 3; x < index_i * 3 + 3; ++x) {  
            for (int y = index_j * 3; y < index_j * 3 + 3; ++y) {  
                if ((x!=i || y != j) && board[x][y] == board[i][j]) { //注意这里逻辑是"或"||，不是"与"  
                    return false;  
                }  
            }  
        }  
        return true;  
    }  
    void solveSudoku(vector<vector<char> > &board) {  
        if (board.size() == 0 || board[0].size() == 0) return; //简洁的方式去验证输入合法性  
        this->isOver = false;  
        dfs(board, 0, 0, 9);  
          
    }  
};  

66ms beat 36.43%

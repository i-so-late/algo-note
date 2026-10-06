#include "data_structures/structures.hpp"

class Solution {
public:
    bool valid(vector<vector<char>>& board, int i, int j){
        //row is valid
        for(int k=0; k<board.size(); ++k){
            if(k==j) continue;
            if(board[i][j] == board[i][k]) return false;
        }
        //col is valid
        for(int k=0; k<board.size(); ++k){
            if(k==i) continue;
            if(board[i][j] == board[k][j]) return false;
        }
        //in cell
        int rowStart = (i / 3)*3;
        int colStart = (j / 3)*3;
        for(int k=rowStart; k<rowStart+3; ++k){
            for(int l = colStart; l<colStart+3; ++l){
                if(k==i && j==l) continue;
                if(board[i][j] == board[k][l]) return false;
            }
        }
        return true;
    }
    bool backTrack(vector<vector<char>>& board){
        for(int i=0; i<board.size();++i){
            for(int j=0; j<board.size();++j){
                if(board[i][j]=='.'){
                    for(char k='1'; k<='9'; ++k){
                        board[i][j] = k;
                        if(valid(board, i, j)){
                            if(backTrack(board)) return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backTrack(board);
    }
};
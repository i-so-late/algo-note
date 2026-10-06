#include "data_structures/structures.hpp"

class Solution {
public:
    vector<string> chessboard;
    vector<vector<string>> res;
    bool judgeConflict(int x, int y){
        //no conflict on col
        for(int i=x-1; i>=0; --i){
            if(chessboard[i][y]=='Q') return false;
        }
        //no conflict on diagonal
        for(int i=x-1, j=y+1; i>=0 && j<chessboard.size(); --i, ++j){
            if(chessboard[i][j]=='Q') return false;
        }
        for(int i=x-1, j=y-1; i>=0 && j>=0; --i, --j){
            if(chessboard[i][j]=='Q') return false;
        }
        return true;
    }
    void backTrack(int n, int start){
        if(start == n){
            res.push_back(chessboard);
            return;
        }
        for(int i = 0; i<n; ++i){
            if(judgeConflict(start, i)){
                chessboard[start][i] = 'Q';
                backTrack(n, start+1);
                chessboard[start][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        chessboard.assign(n,string(n, '.'));
        backTrack(n, 0);
        return res;
    }
};
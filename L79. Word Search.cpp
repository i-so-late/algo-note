#include "data_structures/structures.hpp"

class Solution {
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
public:
    bool backTracking(vector<vector<char>>& board, string word, int begin, string path, vector<vector<bool>>& visited, int x, int y){
        if(path.size() > word.size()) return false;
        if(path.size() == word.size() && path == word) return true;
        for(int i=0; i<4; ++i){
            int newX = x+dirX[i];
            int newY = y+dirY[i];
            if(newX < 0 || newY <0 || newX >= board.size() || newY >= board[0].size()) continue;
            if(visited[newX][newY] || board[newX][newY] != word[begin]) continue;
            visited[newX][newY] = true;
            if(backTracking(board, word, begin+1, path+board[newX][newY], visited, newX, newY)) return true;
            visited[newX][newY] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]!=word[0]) continue;
                visited[i][j] = true;
                if(backTracking(board, word, 1, {board[i][j]}, visited, i, j)) return true;           
                visited[i][j] = false; 
            }
        }
        return false;
    }
};
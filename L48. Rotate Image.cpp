#include "data_structures/structures.hpp"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left = 0, right = n-1;
        while(left < right){
            for(int i=left; i<right; ++i){
                swap(matrix[left][i], matrix[i][right]);
                swap(matrix[left][i], matrix[right][right-i+left]);
                swap(matrix[left][i], matrix[right-i+left][left]);
            }
            ++left;
            --right;
        }
        return;
    }
};
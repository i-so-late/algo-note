#include "data_structures/structures.hpp"

class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        // R[j][d]：以 j 开头、恰好 d 种字母的子串个数
        vector<array<int, 27>> R(n + 1);
        array<int, 26> nxt;
        nxt.fill(n);
        for (int j = n - 1; j >= 0; --j) {
            nxt[s[j] - 'a'] = j;
            vector<int> pos;
            for (int c = 0; c < 26; ++c)
                if (nxt[c] < n) pos.push_back(nxt[c]);
            sort(pos.begin(), pos.end());   // pos[0] == j
            pos.push_back(n);               // 哨兵
            R[j].fill(0);
            for (int d = 1; d < (int)pos.size(); ++d)
                R[j][d] = pos[d] - pos[d - 1];
        }

        long long ans = 0;
        array<int, 26> last;
        last.fill(-1);
        for (int j = 0; j + 1 < n; ++j) {
            last[s[j] - 'a'] = j;
            vector<int> pos;
            for (int c = 0; c < 26; ++c)
                if (last[c] >= 0) pos.push_back(last[c]);
            sort(pos.rbegin(), pos.rend()); // pos[0] == j
            pos.push_back(-1);              // 哨兵
            for (int d = 1; d < (int)pos.size(); ++d) {
                long long L = pos[d - 1] - pos[d];
                ans += L * R[j + 1][d];
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.countMagicalPairs("abcac");
}
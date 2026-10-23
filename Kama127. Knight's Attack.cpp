/*https://kamacoder.com/problempage.php?pid=1203*/

#include "data_structures/structures.hpp"

int grid[1001][1001];
int b1, b2;
int dirctX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dirctY[8] = {1, -1, 2, -2, 2, -2, 1, -1};

// struct Knight{
//     int a1;
//     int a2;
//     int g;
//     double f;
//     bool operator<(const Knight& k) const { return this->f > k.f; }
// };

struct Knight{
    int a1;
    int a2;
    int g;
    int f;
    bool operator<(const Knight& k) const {
        if(f != k.f) return f > k.f;   // f 小的优先
        return g < k.g;                // f 相同时，g 大的优先
    }
};

// double heuristic(int a1, int a2){
//     return sqrt(((b1-a1)*(b1-a1)+(b2-a2)*(b2-a2))/5.0);
// }

int heuristic(int x, int y){
    int dx = abs(x - b1), dy = abs(y - b2);
/*
马走“日”字，每一步都是一个方向走 1 格、另一个方向走 2 格。由此可以得到三条限制：
横向每步最多走 2 格，所以至少需要 dx / 2 步
纵向每步最多走 2 格，所以至少需要 dy / 2 步
横纵加起来每步正好走 3 格（1 + 2），所以至少需要 (dx + dy) / 3 步
*/
    int h = max({(dx + 1) / 2, (dy + 1) / 2, (dx + dy + 2) / 3});
/*
把棋盘想象成国际象棋盘那样黑白相间，格子颜色由 x + y 的奇偶性决定。马每走一步，x + y 的变化是 1 + 2 = 3，或者 1 - 2 = -1 之类，总是奇数。所以马每走一步，所在格子的颜色都会翻转一次。

这就意味着：
dx + dy 为偶数（终点和当前格同色）时，必须走偶数步
dx + dy 为奇数（终点和当前格异色）时，必须走奇数步
*/
    if((h - dx - dy) % 2 != 0) ++h;    // 步数的奇偶性必须和 dx+dy 一致
    return h;
}

int bfs(int a1, int a2){
    memset(grid, 0x3f, sizeof(grid));
    priority_queue<Knight> priQue;
    grid[a1][a2] = 0;
    priQue.push({a1, a2, 0, heuristic(a1, a2)});
    while(!priQue.empty()){
        Knight cur = priQue.top(); priQue.pop();
        if(cur.a1 == b1 && cur.a2 == b2) return cur.g;
        if(cur.g>grid[cur.a1][cur.a2]) continue;
        for(int i=0; i<8; ++i){
            int newX = cur.a1 + dirctX[i];
            int newY = cur.a2 + dirctY[i];
            if(newX > 1000 || newY > 1000 || newX < 1 || newY < 1) continue;
            if(cur.g + 1 < grid[newX][newY]){
                grid[newX][newY] = cur.g + 1;
                priQue.push({newX, newY, cur.g+1, cur.g + 1 + heuristic(newX, newY)});
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int a1, a2;
    while(n--){
        cin >> a1 >> a2 >> b1 >> b2;
        cout << bfs(a1, a2) << endl;
    }
    return 0;
}
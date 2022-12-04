#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100
using namespace std;

int board[MAX + 1][MAX + 1];
int x, y, d, g;

// 우 상 좌 하 (0, 1, 2, 3)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<int> history;

void makeDragonCurve() {
    for(int i=history.size() - 1; i >= 0; i--) {
        int nextDir = (history[i] + 1) % 4; // 시계 방향 90도 회전
        x += dx[nextDir];
        y += dy[nextDir];
        board[y][x] = 1;
        history.push_back(nextDir);
    }
}

bool isSquare(int y, int x) {
    if(board[y][x] && board[y][x+1] && board[y+1][x] && board[y+1][x+1]) 
        return true;
    return false;
}

int main() {
    int N, answer = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int d, g;
        cin >> x >> y >> d >> g;
        board[y][x] = 1;
        x += dx[d];
        y += dy[d];
        board[y][x] = 1;
        history.push_back(d);

        for(int i=0; i<g; i++){
            makeDragonCurve();
        }

        history.clear();
    }

    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            if(isSquare(i, j)) answer++;
        }
    }
    cout << answer;
}
#include <iostream>
#define MAX 50
#include <queue>

using namespace std;

int N, L, R;
bool isOpen[MAX][MAX];
int contries[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 1};
struct Point {
    int x, y;
};

void move(int sum, int count, vector<Point> connect) {
    int afterMove = sum / count;
    for(int i=0; i<connect.size(); i++) {
        contries[connect[i].y][connect[i].x] = afterMove;
    }
}

int bfs(int i, int j) {
    queue<Point> q; 
    vector<Point> connect;
    int sum, count;
    q.push({j, i});

    while(!q.empty()){
        Point curr = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) 
                continue;
            int gap = abs(contries[curr.y][curr.x] - contries[ny][nx]);
            if(gap >= L && gap <= R) {
                isOpen[ny][nx] = 1;
                sum += contries[ny][nx];
                count++;
                q.push({ny, nx});
                connect.push_back({ny, nx});
            }
        }
    }
    if(count == 0) return 0;
    move(sum, count, connect);
    return count;
}

int main() {
    cin >> N >> L >> R;
    int answer = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> contries[i][j];
        }
    }

    while(true) {
        memset(isOpen, false, sizeof(isOpen));
        int count = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!isOpen[i][j]){
                    count += bfs(i,j);
                }
            }
        }
        if(count == 0) break;
        answer++;
    }
    cout << answer;
}
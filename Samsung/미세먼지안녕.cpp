#include<iostream>
#include<vector>

using namespace std;

int R, T, C;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> cleaner;
vector<vector<int>> room;

int getAnswer() {
    int answer = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(room[i][j] > 0) 
            answer += room[i][j];
        }
    }
    return answer;
}
void spread() {
    vector<vector<int>> temp = room;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(room[i][j] <= 0) continue;
            int count = 0;
            for(int k=0; k<4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if(room[ny][nx] < 0) continue;

                temp[ny][nx] += (room[i][j] / 5);
                count++;
            }
            temp[i][j] = temp[i][j] - room[i][j]/5 * count;
        }
    }
    
    room = temp;
}

void refresh() { 
    // 위 (반시계)
    for(int i=cleaner[0] - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];
    for(int i=0; i < C - 1; i++)
        room[0][i] = room[0][i+1];   
    for(int i=1; i <= cleaner[0]; i++)
        room[i - 1][C - 1] = room[i][C - 1];
    for(int i = C - 1; i > 1; i--)
        room[cleaner[0]][i] = room[cleaner[0]][i - 1];
    room[cleaner[0]][1] = 0;

    // 아래 (시계)
    for(int i=cleaner[1] + 1; i < R - 1; i++)
        room[i][0] = room[i + 1][0];
    for(int i=0; i < C - 1; i++)
        room[R - 1][i] = room[R - 1][i+1];   
    for(int i=R - 1; i > cleaner[1]; i--)
        room[i][C - 1] = room[i - 1][C - 1];
    for(int i = C - 1; i > 1; i--)
        room[cleaner[1]][i] = room[cleaner[1]][i - 1];
    room[cleaner[1]][1] = 0;
} 

int main() {
    cin >> R >> C >> T;
    room.resize(R, vector<int>(C));
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> room[i][j];
            if(room[i][j] == -1) {
                cleaner.push_back(i);
            }
        }
    }
    
    while(T--) {
        spread();
        refresh();
    }
    cout << getAnswer();
}


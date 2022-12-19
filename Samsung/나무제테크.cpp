#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 10

using namespace std;
int N, M, K;
int answer;
int A[MAX_N + 1][MAX_N + 1];
int ground[MAX_N + 1][MAX_N + 1];
vector<int> trees[MAX_N + 1][MAX_N + 1];
vector<vector<int>> deads;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(trees[i][j].size() == 0) continue;
            for(auto &tree : trees[i][j]) {
                if(tree > ground[i][j]){
                    deads[i][j] += tree;
                } else {
                    ground[i][j] -= tree;
                    tree++;
                }
            }
        }
    }
} 

void summer() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(auto &tree : trees[i][j]) {
                if(tree < 0){
                    ground[i][j] += (-tree)/2;
                }
            }
        }
    }    
}

void fall() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(auto &tree : trees[i][j]) {
                if(tree > 0 && tree % 5 == 0){
                    for(int k=0; k<8; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        trees[ny][nx].push_back(1);
                    }
                }
            }
        }
    }    
}

void winter() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            ground[i][j] += A[i][j];
        }
    }  
}

void find() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(auto &tree : trees[i][j]) {
                if(tree > 0) answer++;
            }
        }
    }  
}

int main() {
    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> A[i][j];
            ground[i][j] = 5;
        }
    }

    while(M--) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back(z);    // 정렬필요
    }

    while(K--) {
        spring();
        summer();
        fall();
        winter();
    }

    find();
    cout << answer;
    return 0;
}